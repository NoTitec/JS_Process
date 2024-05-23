#include "stdafx.h"
#include "KHR_Bullet.h"
#include "ScrollMgr.h"

CKHR_Bullet::CKHR_Bullet()
{
}

CKHR_Bullet::~CKHR_Bullet()
{
}

void CKHR_Bullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CKHR_Bullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CKHR_Bullet::Late_Update()
{
}

void CKHR_Bullet::Render(HDC hDC)
{
	int iScroll = SCROLL.Get_ScrollX();
	Ellipse(hDC, m_tRect.left + iScroll, m_tRect.top, m_tRect.right + iScroll, m_tRect.bottom);
}

void CKHR_Bullet::Release()
{
}

void CKHR_Bullet::OnHit(CObj* _pObj)
{
}
