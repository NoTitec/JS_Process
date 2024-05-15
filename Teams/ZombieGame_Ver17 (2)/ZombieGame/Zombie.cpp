#include "pch.h"
#include "HpBar.h"
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
		m_dwTime = GetTickCount();
		Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		m_tInfo.fCX = 20.0f;
		m_tInfo.fCY = 20.0f;
		m_fSpeed = 2.0f;
		m_fmaxSpeed = 2.f;
		m_iHP = 2;
		m_iFullHp = 2;
		break;
	case 1:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		m_tInfo.fCX = 30.0f;
		m_tInfo.fCY = 30.0f;
		m_fSpeed = 1.5f;
		m_fmaxSpeed = 1.5f;
		m_iHP = 3;
		// 체력바를 위해 추가했습니다. 신경 쓸 필요 x
		m_iFullHp = 3;
		break;
	case 2:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		m_tInfo.fCX = 60.0f;
		m_tInfo.fCY = 60.0f;
		m_fSpeed = 0.5f;
		m_fmaxSpeed = 0.5f;
		m_iHP = 10;
		// 체력바를 위해 추가했습니다. 신경 쓸 필요 x
		m_iFullHp = 10;
		break;
	}

}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	if (m_fSpeed < m_fmaxSpeed)
	{
		m_fSpeed += 0.1f;
	}
	CObj::Update_Rect();
	Pos_Hp_Bar_Update();
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


	// 체력바 UI 신경 쓸 필요 X
	::Rectangle(_hdc, m_tHpBarRect.left, m_tHpBarRect.top, m_tHpBarRect.right, m_tHpBarRect.bottom);
	
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 87, 51));
	oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

	int iHitNumber = m_iFullHp - m_iHP;
	int iHpInterval = m_tHpBarInfo.fCX / m_iFullHp;
	int iCurrentHpRight = m_tHpBarRect.right - (iHpInterval * iHitNumber);
	::Rectangle(_hdc, m_tHpBarRect.left, m_tHpBarRect.top, iCurrentHpRight, m_tHpBarRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(redBrush);
	// 체력바 UI
}

void CZombie::Release()
{

}

void CZombie::Set_Speed_Zero()
{
	switch (m_iType)
	{
	case 0:
	case 1:
		m_fSpeed = 0.f;
		break;
	}
}

void CZombie::Move_Zombie()
{
	//플레이어 방향으로 이동
	switch (m_iType)
	{
	case 1:
		if (m_fdistance < 130.f)
		{
			m_fSpeed = 3.f;
		}
		break;
	}
	float fMoveDistance = (m_fdistance >= m_fSpeed) ? m_fSpeed : m_fdistance;
	m_tInfo.fX += (m_vDir.fX * fMoveDistance);
	m_tInfo.fY += (m_vDir.fY * fMoveDistance);
}

void CZombie::Dir_Update()
{
	Vec2 vMyPos = Get_Pos();
	m_vDir = m_vTargetPos - vMyPos;
	switch (m_iType)
	{
	case 0:
		if (m_bRandDir == false)
		{
			if (m_dwTime + 500 < GetTickCount())
			{
				m_bRandDir = true;
				m_dwTime = GetTickCount();
			}
		}
		else
		{
			if (m_dwTime + 500 < GetTickCount())
			{
				m_bRandDir = false;
				m_dwTime = GetTickCount();
			}
			m_vDir.fX += 200.f;
			m_vDir.fY += 200.f;
		}
		break;
	}
	m_fdistance = m_vDir.Length();
	m_vDir.Normalize();
}

void CZombie::Pos_Hp_Bar_Update()
{
	m_tHpBarInfo.fCX = (m_tRect.right - m_tRect.left) * 2;
	m_tHpBarInfo.fCY = 10.0f;
	m_tHpBarInfo.fY = m_tInfo.fY - m_tInfo.fCY / 2.0f - 10.0f;
	m_tHpBarInfo.fX = m_tInfo.fX;

	m_tHpBarRect.left = long(m_tHpBarInfo.fX - m_tHpBarInfo.fCX / 2.0f);
	m_tHpBarRect.right = long(m_tHpBarInfo.fX + m_tHpBarInfo.fCX / 2.0f);
	m_tHpBarRect.top = long(m_tHpBarInfo.fY - m_tHpBarInfo.fCY / 2.0f);
	m_tHpBarRect.bottom = long(m_tHpBarInfo.fY + m_tHpBarInfo.fCY / 2.0f);
}