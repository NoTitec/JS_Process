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
CKSHPlayer::CKSHPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f)
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
		//¸ÊÅ©±â¹þ¾î³ª·ÁÇÏ¸é Áõ°¡ ¾È½ÃÅ´
		if(m_tInfo.fX<=MAPSIZEXMAX)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_LEFT))
		//¸ÊÅ©±â¹þ¾î³ª·ÁÇÏ¸é Áõ°¡ ¾È½ÃÅ´
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
	if (KEY.Key_Down('F'))
	{
		OBJ.Add_Object(OBJ_PLAYER_BULLET, Create_Bullet<CBullet>());
	}
}

void CKSHPlayer::Jump()
{
	float fY(0.f);

	bool bLineCol = KSH_LINE.Collision_Line(m_tInfo.fX, &fY);

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