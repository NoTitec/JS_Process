#include "ScrewBullet.h"
#include "stdafx.h"
CScrewBullet::CScrewBullet()
{
    ZeroMemory(&m_tCenter, sizeof(POINT));
}

CScrewBullet::~CScrewBullet()
{
    Release();
}

void CScrewBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;

	m_bStart = true;

	m_fRotAngle = 0.f;
	m_fDistance = 20.f;
	m_fRotSpeed = 30.f;
}

int CScrewBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	//시작했을때 미사일 회전 중심 center는 
	if (m_bStart)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;

		m_bStart = false;
	}
	//안보이는 회전 기준점 회전
	m_tCenter.x += long(m_fSpeed * cos(m_fAngle * (PI / 180.f)));
	m_tCenter.y -= long(m_fSpeed * sin(m_fAngle * (PI / 180.f)));
	m_fRotAngle += m_fRotSpeed;
	//회전 기준점 m_tCenter서부터 m_RotAngle만큼 회전하고 m_fDistance만큼 떨어진 위치에 미사일 중점 위치시키기
	m_tInfo.fX = m_tCenter.x + (m_fDistance * cos(m_fRotAngle * (PI / 180.f)));
	m_tInfo.fY = m_tCenter.y - (m_fDistance * sin(m_fRotAngle * (PI / 180.f)));
    
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CScrewBullet::Late_Update()
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right ||
		0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		Set_Dead();
	}
}

void CScrewBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CScrewBullet::Release()
{
}
