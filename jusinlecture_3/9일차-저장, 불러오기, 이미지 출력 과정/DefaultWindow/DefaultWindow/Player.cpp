#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "Shield.h"
#include "ScrewBullet.h"
#include "ObjMgr.h"
#include "GuideBullet.h"
#include "KeyMgr.h"
#include "LineMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CPlayer::CPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f)
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { 100.f, WINCY / 2.f, 60.f, 60.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/maja2.bmp", L"Player");
}

int CPlayer::Update()
{
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	Jump();
	Offset();

}

void CPlayer::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	// Rectangle(hDC,
	// 	m_tRect.left + iScrollX,
	// 	m_tRect.top, 
	// 	m_tRect.right + iScrollX,
	// 	m_tRect.bottom);

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Player");

	// BitBlt(hDC,			// 복사 받을 최종적인 그리기 DC
	// 	m_tRect.left + iScrollX,	// 복사 받을 위치 X좌표
	// 	m_tRect.top,				// 복사 받을 위치 Y좌표
	// 	(int)m_tInfo.fCX,			// 복사 받을 가로 사이즈
	// 	(int)m_tInfo.fCY,			// 복사 받을 가로 사이즈
	// 	hMemDC,						// 복사할 이미지 DC
	// 	0, 0,						// 복사할 이미지의 출력 시작 좌표(left,top)
	// 	SRCCOPY);					// 그대로 출력

	GdiTransparentBlt(hDC,
						m_tRect.left + iScrollX, 
						m_tRect.top, 
						(int)m_tInfo.fCX, 
						(int)m_tInfo.fCY, 
						hMemDC, 
						0, 0, 
						(int)m_tInfo.fCX,
						(int)m_tInfo.fCY,
						RGB(255, 255, 255));
}

void CPlayer::Release()
{
}

template<typename T>
CObj * CPlayer::Create_Bullet()
{
	CObj*		pBullet = CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}

void CPlayer::Key_Input()
{
	//float fY(0.f);

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;

		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY))
			m_tInfo.fY = fY;*/
	}
		
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	
		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY))
			m_tInfo.fY = fY;*/
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE))
	{
		m_bJump = true;
	}

}


CObj * CPlayer::Create_Shield()
{
	CObj*		pShield = CAbstractFactory<CShield>::Create();
	pShield->Set_Target(this);

	return pShield;
}

void CPlayer::Jump()
{
	float fY(0.f);

	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_tInfo.fY -= (m_fPower * m_fTime) - ((9.8f * m_fTime * m_fTime) * 0.5f);

		m_fTime += 0.2f;

		if (bLineCol && (fY < m_tInfo.fY))
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY;
	}

		
}

void CPlayer::Offset()
{
	int	iOffSetminX = 100;
	int	iOffSetmaxX = 700;

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);


}

