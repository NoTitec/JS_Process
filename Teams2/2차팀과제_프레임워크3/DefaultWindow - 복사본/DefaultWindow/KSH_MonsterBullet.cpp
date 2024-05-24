#include "stdafx.h"
#include "KSH_MonsterBullet.h"
#include "KSH.h"
#include "ScrollMgr.h"

CKSH_MonsterBullet::CKSH_MonsterBullet()
{
	m_bDead = false;
}

CKSH_MonsterBullet::~CKSH_MonsterBullet()
{
    Release();
}

void CKSH_MonsterBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
	Set_ID(OBJ_MONSTER_BULLET);
}

int CKSH_MonsterBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	
	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_RU:
		m_tInfo.fY += m_fSpeed;
		m_tInfo.fX += m_fSpeed;
		break;
	case DIR_LU:
		m_tInfo.fY += m_fSpeed;
		m_tInfo.fX -= m_fSpeed;
		break;
	default:
		break;
	
	
	//m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
	//m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CKSH_MonsterBullet::Late_Update()
{
	if (MAPSIZEXMIN >= m_tInfo.fX - (m_tInfo.fCX * 0.5f) || MAPSIZEXMAX <= m_tInfo.fX + (m_tInfo.fCX * 0.5f) ||
		0 >= m_tInfo.fY - (m_tInfo.fCY * 0.5f) || WINCY <= m_tInfo.fY + (m_tInfo.fCY * 0.5f))
	{
		Set_Dead();
	}
}

void CKSH_MonsterBullet::Render(HDC hDC)
{
	int iScrollX = SCROLL.Get_ScrollX();
	int iScrollY = SCROLL.Get_ScrollY();

	Ellipse(hDC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);

}

void CKSH_MonsterBullet::Release()
{
}

void CKSH_MonsterBullet::OnHit(CObj* _pObj)
{

}
