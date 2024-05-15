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
	// CBomb Initialize
}

int CBomb::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	// CBomb Update

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CBomb::Late_Update()
{
	// CBomb Late_Update
}

void CBomb::Render(HDC _hdc)
{
	// CBomb Render








	// 진우형의 그리기
	/*HBRUSH bombBrush = CreateSolidBrush(RGB(255, 250, 250));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, bombBrush);
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(bombBrush);*/
}

void CBomb::Release()
{
	// CBomb Release
}
