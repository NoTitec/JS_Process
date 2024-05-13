#include "pch.h"
#include "Zombie.h"

CZombie::CZombie()
{

}

CZombie::~CZombie()
{
	Release();
}

void CZombie::Initialize()
{
	// CZombie Initialize
	int itemp = rand() % 3;

	switch (itemp)
	{
	case 0:
		HBRUSH Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		m_eZtype = NORMAL_ZOMBIE;
		m_tInfo.fCX = 40.0f;
		m_tInfo.fCY = 40.0f;
		m_fSpeed = 5.0f;
		break;
	case 1:
		HBRUSH Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		m_eZtype = LIGHT_ZOMBIE;
		m_tInfo.fCX = 20.0f;
		m_tInfo.fCY = 20.0f;
		m_fSpeed = 7.0f;
		break;
	case 2:
		HBRUSH Brush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		m_eZtype = HEAVY_ZOMBIE;
		m_tInfo.fCX = 60.0f;
		m_tInfo.fCY = 60.0f;
		m_fSpeed = 2.0f;
		break;
	}
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{
	// CZombie Update
	Dir_Update();

	Move_Zombie();
}

void CZombie::Render(HDC _hdc)
{
	/*HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(oldBrush);*/
}

void CZombie::Release()
{

}

void CZombie::Dir_Update()
{
	//플레이어 방향추적
	Vec2 vMyPos = Get_Pos();
	m_vDir = m_vTargetPos - vMyPos;
	m_fdistance = m_vDir.Length();
	m_vDir.Normalize();
}

void CZombie::Move_Zombie()
{
	//플레이어 방향으로 이동
	float fMoveDistance = (m_fdistance >= m_fSpeed) ? m_fSpeed : m_fdistance;
	m_tInfo.fX += (m_vDir.fX * fMoveDistance);
	m_tInfo.fY += (m_vDir.fY * fMoveDistance);
}
