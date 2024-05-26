#include "Player.h"
#include "Bullet.h"
#include "ScrewBullet.h"
#include "GuideBullet.h"
#include "Shield.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "LineMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CPlayer::CPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f)
, m_eCurState(IDLE), m_ePreState(ST_END)
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { 100.f, WINCY / 2.f, 200.f, 200.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;

	//비트이미지 가로
	m_tFrame.iFrameStart = 0;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 3;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.dwSpeed = 200;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_DOWN.bmp", L"Player_DOWN");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_UP.bmp", L"Player_UP");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LEFT.bmp", L"Player_LEFT");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RIGHT.bmp", L"Player_RIGHT");

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LU.bmp", L"Player_LU");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RU.bmp", L"Player_RU");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LD.bmp", L"Player_LD");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RD.bmp", L"Player_RD");

	m_pFrameKey = L"Player_DOWN";
	m_eCurState = IDLE;

}

int CPlayer::Update()
{
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	//Jump();
	Offset();
	Motion_Change();

	__super::Move_Frame();

}

void CPlayer::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		(int)m_tInfo.fCX * m_tFrame.iFrameStart,
		(int)m_tInfo.fCY * m_tFrame.iMotion,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(0, 0, 0));
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	//float fY(0.f);

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		m_pFrameKey = L"Player_RIGHT";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = L"Player_LEFT";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
		m_pFrameKey = L"Player_UP";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
		m_pFrameKey = L"Player_DOWN";
		m_eCurState = WALK;
	}

	else
		m_eCurState = IDLE;

}


CObj* CPlayer::Create_Shield()
{
	CObj* pShield = CAbstractFactory<CShield>::Create();
	pShield->Set_Target(this);

	return pShield;
}

void CPlayer::Jump()
{
	//선의 y좌표저장용
	float fY(0.f);
	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fY);
	//점프중이면
	if (m_bJump)
	{
			//플레이어 y좌표 포물선 갱신
			m_fTime += 0.2f;
			m_tInfo.fY -= (m_fPower * m_fTime) - ((9.8f * m_fTime * m_fTime) * 0.5f);
			
	}

	//만약 바닥에 선이있고 지형의 y좌표보다 플레이어 좌표가 아래면 플레이어 점프상태 false로 만들고 플레이어좌표 선y좌표로 대입
	if (bLineCol && (fY <= m_tInfo.fY))
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
	//점프중 아니면 항상 떨어지는중
	if (!m_bJump)
	{
		if (m_isFalling)
		{
			m_fTime += 0.2f;
			m_tInfo.fY += ((9.8f * m_fTime * m_fTime) * 0.5f);
		}
		if (fY > m_tInfo.fY)
		{
			m_isFalling = true;
		}
		if (bLineCol && (fY-30.f <= m_tInfo.fY))
		{
			m_isFalling = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
		if (!bLineCol)
		{
			m_isFalling = true;
		}

	}


}

void CPlayer::Offset()
{
	int	iOffSetminX = 100;
	int	iOffSetmaxX = 700;

	int	iOffSetminY = 100;
	int	iOffSetmaxY = 500;

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (iOffSetminY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetmaxY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
}

void CPlayer::Motion_Change()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case CPlayer::IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;
		case CPlayer::WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 1;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;

		case CPlayer::ATTACK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 2;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;

		case CPlayer::HIT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iMotion = 3;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;

		case CPlayer::DEAD:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 4;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;
		}

		m_ePreState = m_eCurState;
	}
}
//CPlayer::CPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f),m_isFalling(false), m_eCurState(IDLE), m_ePreState(ST_END)
//{
//	ZeroMemory(&m_tBarrel, sizeof(POINT));
//}
//
//
//CPlayer::~CPlayer()
//{
//	Release();
//}
//
//void CPlayer::Initialize()
//{
//	m_tInfo = { WINCX / 2.f, WINCY / 2.f,  200.f, 200.f };
//	m_fSpeed = 10.f;
//	m_fDistance = 100.f;
//	m_fPower = 17.f;
//	//m_Past_fX = m_tInfo.fX;
//
//	//비트이미지 가로
//	m_tFrame.iFrameStart = 0;
//	//비트이미지 최대 개수
//	m_tFrame.iFrameEnd = 3;
//	//비트이미지 세로
//	m_tFrame.iMotion = 0;
//	m_tFrame.dwTime = GetTickCount();
//	m_tFrame.dwSpeed = 200;
//
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_DOWN.bmp", L"Player_DOWN");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_UP.bmp", L"Player_UP");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LEFT.bmp", L"Player_LEFT");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RIGHT.bmp", L"Player_RIGHT");
//
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LU.bmp", L"Player_LU");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RU.bmp", L"Player_RU");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_LD.bmp", L"Player_LD");
//	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player/Player_RD.bmp", L"Player_RD");
//
//	m_pFrameKey = L"Player_DOWN";
//	m_eCurState = IDLE;
//}
//
//int CPlayer::Update()
//{
//	Key_Input();
//	__super::Update_Rect();
//
//	return OBJ_NOEVENT;
//}
//
//void CPlayer::Late_Update()
//{
//	//Jump();
//	//m_tBarrel.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle/180.f*PI));
//	//m_tBarrel.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
//	Offset();
//	Motion_Change();
//	__super::Move_Frame();
//}
//
//void CPlayer::Render(HDC hDC)
//{
//	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
//	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
//
//	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
//	// 포신 그리기
//	//MoveToEx(hDC, (int)m_tInfo.fX+iScrollX, (int)m_tInfo.fY, NULL);
//	//LineTo(hDC, m_tBarrel.x+iScrollX, m_tBarrel.y);
//
//	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);
//	GdiTransparentBlt(hDC,
//		m_tRect.left + iScrollX,
//		m_tRect.top+ iScrollY,
//		(int)m_tInfo.fCX,
//		(int)m_tInfo.fCY,
//		hMemDC,
//		0, 0,
//		(int)m_tInfo.fCX * m_tFrame.iFrameStart,
//		(int)m_tInfo.fCY * m_tFrame.iMotion,
//		RGB(0, 0, 0));
//}
//
//void CPlayer::Release()
//{
//}
//
//void CPlayer::Jump()
//{
//	//선의 y좌표저장용
//	float fY(0.f);
//	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fY);
//	//점프중이면
//	if (m_bJump)
//	{
//			//플레이어 y좌표 포물선 갱신
//			m_fTime += 0.2f;
//			m_tInfo.fY -= (m_fPower * m_fTime) - ((9.8f * m_fTime * m_fTime) * 0.5f);
//			
//	}
//
//	//만약 바닥에 선이있고 지형의 y좌표보다 플레이어 좌표가 아래면 플레이어 점프상태 false로 만들고 플레이어좌표 선y좌표로 대입
//	if (bLineCol && (fY <= m_tInfo.fY))
//		{
//			m_bJump = false;
//			m_fTime = 0.f;
//			m_tInfo.fY = fY;
//		}
//	//점프중 아니면 항상 떨어지는중
//	if (!m_bJump)
//	{
//		if (m_isFalling)
//		{
//			m_fTime += 0.2f;
//			m_tInfo.fY += ((9.8f * m_fTime * m_fTime) * 0.5f);
//		}
//		if (fY > m_tInfo.fY)
//		{
//			m_isFalling = true;
//		}
//		if (bLineCol && (fY-30.f <= m_tInfo.fY))
//		{
//			m_isFalling = false;
//			m_fTime = 0.f;
//			m_tInfo.fY = fY;
//		}
//		if (!bLineCol)
//		{
//			m_isFalling = true;
//		}
//
//	}
//	
//}
//
//void CPlayer::Offset()
//{
//	int	iOffSetminX = 100;
//	int	iOffSetmaxX = 700;
//	int	iOffSetminY = 100;
//	int	iOffSetmaxY = 500;
//	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
//	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
//
//	if (iOffSetminX > m_tInfo.fX + iScrollX)
//		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);
//
//	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
//		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
//	if (iOffSetminY > m_tInfo.fY + iScrollY)
//		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);
//
//	if (iOffSetmaxY < m_tInfo.fY + iScrollY)
//		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
//
//}
//
//void CPlayer::Motion_Change()
//{
//	if (m_ePreState != m_eCurState)
//	{
//		switch (m_eCurState)
//		{
//		case CPlayer::IDLE:
//			m_tFrame.iFrameStart = 0;
//			m_tFrame.iFrameEnd = 3;
//			m_tFrame.iMotion = 0;
//			m_tFrame.dwTime = GetTickCount();
//			m_tFrame.dwSpeed = 200;
//			break;
//		case CPlayer::WALK:
//			m_tFrame.iFrameStart = 0;
//			m_tFrame.iFrameEnd = 5;
//			m_tFrame.iMotion = 1;
//			m_tFrame.dwTime = GetTickCount();
//			m_tFrame.dwSpeed = 200;
//			break;
//
//		case CPlayer::ATTACK:
//			m_tFrame.iFrameStart = 0;
//			m_tFrame.iFrameEnd = 5;
//			m_tFrame.iMotion = 2;
//			m_tFrame.dwTime = GetTickCount();
//			m_tFrame.dwSpeed = 200;
//			break;
//
//		case CPlayer::HIT:
//			m_tFrame.iFrameStart = 0;
//			m_tFrame.iFrameEnd = 1;
//			m_tFrame.iMotion = 3;
//			m_tFrame.dwTime = GetTickCount();
//			m_tFrame.dwSpeed = 200;
//			break;
//
//		case CPlayer::DEAD:
//			m_tFrame.iFrameStart = 0;
//			m_tFrame.iFrameEnd = 3;
//			m_tFrame.iMotion = 4;
//			m_tFrame.dwTime = GetTickCount();
//			m_tFrame.dwSpeed = 200;
//			break;
//		}
//
//		m_ePreState = m_eCurState;
//	}
//}
//
//template<typename T>
//CObj* CPlayer::Create_Bullet()
//{
//	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tBarrel.x, (float)m_tBarrel.y);
//	pBullet->Set_Angle(m_fAngle);
//
//	return pBullet;
//}
//CObj* CPlayer::Create_Shield(float _Angle)
//{
//	CObj* pShield = CAbstractFactory<CShield>::Create(m_fAngle+_Angle);
//	pShield->Set_Target(this);
//	return pShield;
//}
//void CPlayer::Key_Input()
//{
//	// GetKeyState()
//	//if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
//	//{
//	//	//왼이나 오른쪽이 눌려있었던상태면 얘를 
//	//	//점프
//	//	m_bJump = true;
//	//}
//	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
//	{
//		//m_Past_fX = m_tInfo.fX;
//		m_tInfo.fX += m_fSpeed;
//		m_pFrameKey = L"Player_RIGHT";
//		m_eCurState = WALK;
//	}
//	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
//	{
//		//m_Past_fX = m_tInfo.fX;
//		m_tInfo.fX -= m_fSpeed;
//		m_pFrameKey = L"Player_LEFT";
//		m_eCurState = WALK;
//		/*float fY(0.f);
//		bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fY);
//		if (fY - m_tInfo.fY > 50.f)
//		{
//			m_isFalling = true;
//		}*/
//	}
//
//	else if (GetAsyncKeyState(VK_DOWN))
//	{
//		m_tInfo.fY += m_fSpeed;
//		m_pFrameKey = L"Player_DOWN";
//		m_eCurState = WALK;
//	}
//
//	else if (GetAsyncKeyState(VK_UP))
//	{
//		m_tInfo.fY -= m_fSpeed;
//		m_pFrameKey = L"Player_UP";
//		m_eCurState = WALK;
//		//m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
//		//m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
//	}
//	else
//		m_eCurState = IDLE;
//	/*if (CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
//	{
//		m_tInfo.fY += 10.1f; m_isFalling = true;
//	}
//	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
//	{
//		m_fAngle += 5.f;
//	}
//	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
//	{
//		m_fAngle -= 5.f;
//	}
//	if (CKeyMgr::Get_Instance()->Key_Down('F'))
//	{
//		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CBullet>());
//	}
//	if (CKeyMgr::Get_Instance()->Key_Down('R'))
//	{
//		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CScrewBullet>());
//	}
//	if (CKeyMgr::Get_Instance()->Key_Down('G'))
//	{
//		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CGuideBullet>());
//	}
//	if (CKeyMgr::Get_Instance()->Key_Down('S'))
//	{
//		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(0.f));
//		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(90.f));
//		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(180.f));
//		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(270.f));
//
//	}*/
//
//}
