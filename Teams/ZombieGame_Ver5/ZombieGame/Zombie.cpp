#include "pch.h"
#include "Zombie.h"

CZombie::CZombie() : m_bStuck(false)
{
	
}

CZombie::~CZombie()
{
	Release();
}

void CZombie::Initialize()
{
	switch (m_iType)
	{
	case 0:
		Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		m_tInfo.fCX = 20.0f;
		m_tInfo.fCY = 20.0f;
		m_fSpeed = 2.0f;
		break;
	case 1:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		m_tInfo.fCX = 30.0f;
		m_tInfo.fCY = 30.0f;
		m_fSpeed = 1.5f;
		break;
	case 2:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		m_tInfo.fCX = 60.0f;
		m_tInfo.fCY = 60.0f;
		m_fSpeed = 0.5f;
		break;
	}
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{
	Dir_Update();
	Move_Zombie();
}

void CZombie::Render(HDC _hdc)
{
	HBRUSH brush = Brush;
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, brush);

	switch ((OBJ_ZOMBIE_TYPE)m_iType)
	{
	case  OBJ_MIDDLE_ZOMBIE:		::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		::SelectObject(_hdc, oldBrush);
		::DeleteObject(oldBrush);
		break;
	case  OBJ_LIGHT_ZOMBIE:
		::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		::SelectObject(_hdc, oldBrush);
		::DeleteObject(oldBrush);
		break;
	case OBJ_HEAVY_ZOMBIE:
		::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		::SelectObject(_hdc, oldBrush);
		::DeleteObject(oldBrush);
		break;
	default:
		break;
	}
	//::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CZombie::Release()
{
	
}

void CZombie::Move_Zombie()
{
	//플레이어 방향으로 이동
	float fMoveDistance = (m_fdistance >= m_fSpeed) ? m_fSpeed : m_fdistance;
	m_tInfo.fX += (m_vDir.fX * fMoveDistance);
	m_tInfo.fY += (m_vDir.fY * fMoveDistance);
}

void CZombie::Dir_Update()
{
	//플레이어 방향추적
	Vec2 vMyPos = Get_Pos();
	m_vDir = m_vTargetPos - vMyPos;
	m_fdistance = m_vDir.Length();
	m_vDir.Normalize();
}

