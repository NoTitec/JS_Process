#include "pch.h"
#include "Bomb.h"

const float CBomb::BOMB_RADIUS = 250.0f;

CBomb::CBomb()
{

}

CBomb::~CBomb()
{
	Release();
}

void CBomb::Initialize()
{
	m_tInfo.fCX = 0.f;
	m_tInfo.fCY = 0.f;
}

int CBomb::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	if (BOMB_RADIUS >= m_tInfo.fCX && BOMB_RADIUS >= m_tInfo.fCY)
	{
		m_tInfo.fCX += 20.0f;
		m_tInfo.fCY += 20.0f;
	}

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CBomb::Late_Update()
{
	if (BOMB_RADIUS <= m_tInfo.fCX && BOMB_RADIUS <= m_tInfo.fCY)
	{
		m_bDead = true;
	}
}

void CBomb::Render(HDC _hdc)
{
	HBRUSH bombBrush = CreateSolidBrush(RGB(255, 250, 250));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, bombBrush);
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(bombBrush);
}

void CBomb::Release()
{

}
