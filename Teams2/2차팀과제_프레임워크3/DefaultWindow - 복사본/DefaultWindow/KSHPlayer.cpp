#include "stdafx.h"
#include "KSH.h"
#include "KSHPlayer.h"
#include "KSH_LineMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "Bullet.h"
#include "AbstractFactory.h"
CKSHPlayer::CKSHPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f), m_isFalling(false)
{
    ZeroMemory(&m_tBarrel, sizeof(POINT));

}

CKSHPlayer::~CKSHPlayer()
{
    Release();

}

void CKSHPlayer::OnHit(CObj* _pObj)
{
	
}

void CKSHPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 60.f, 60.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;
	BMP.Insert_Bmp(L"../Image/maja2.bmp", L"KSH_Player");
	Set_ID(OBJ_PLAYER);
}

int CKSHPlayer::Update()
{
	Key_Input();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CKSHPlayer::Late_Update()
{
	m_tBarrel.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle / 180.f * PI));
	m_tBarrel.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
	Jump();
	Offset();
}

void CKSHPlayer::Render(HDC hDC)
{
	int	iScrollX = (int)SCROLL.Get_ScrollX();
	HDC hMemDC = BMP.Find_Img(L"KSH_Player");

	//Rectangle(hDC, m_tRect.left+iScrollX, m_tRect.top, m_tRect.right+iScrollX, m_tRect.bottom);
	MoveToEx(hDC, (int)m_tInfo.fX + iScrollX, (int)m_tInfo.fY, NULL);
	LineTo(hDC, m_tBarrel.x + iScrollX, m_tBarrel.y);

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

void CKSHPlayer::Release()
{
}

void CKSHPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
		//맵크기벗어나려하면 증가 안시킴
		if(m_tInfo.fX<=MAPSIZEXMAX)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_LEFT))
		//맵크기벗어나려하면 증가 안시킴
		if(m_tInfo.fX>=MAPSIZEXMIN)
		m_tInfo.fX -= m_fSpeed;
	if (KEY.Key_Pressing('A'))
	{
		m_fAngle += 5.f;
	}
	if (KEY.Key_Pressing('D'))
	{
		m_fAngle -= 5.f;
	}
	if (KEY.Key_Pressing(VK_SPACE))
	{
		m_bJump = true;
	}
	if (KEY.Key_Down(VK_DOWN))
	{
		m_tInfo.fY += 10.1f; m_isFalling = true;
	}
	if (KEY.Key_Down('F'))
	{
		OBJ.Add_Object(OBJ_PLAYER_BULLET, Create_Bullet<CBullet>());
	}
}

void CKSHPlayer::Jump()
{
	//선의 y좌표저장용
	float fY(0.f);
	bool bLineCol = KSH_LINE.Collision_Line(m_tInfo.fX, m_tInfo.fY, &fY);
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
		if (bLineCol && (fY - 30.f <= m_tInfo.fY))
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

void CKSHPlayer::Offset()
{
	int	iOffSetminX = 300;
	int	iOffSetmaxX = 500;

	int	iScrollX = (int)SCROLL.Get_ScrollX();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(-m_fSpeed);
}

template<typename T>
CObj* CKSHPlayer::Create_Bullet()
{
	int	iScrollX = (int)SCROLL.Get_ScrollX();
	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tBarrel.x+ iScrollX, (float)m_tBarrel.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_ID(OBJ_PLAYER_BULLET);
	return pBullet;
}