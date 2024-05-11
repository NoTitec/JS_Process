#include "pch.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	// Bullet Initialize
}

int CBullet::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	// Bullet Update

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	// Bullet Late_Update
}

void CBullet::Render(HDC _hdc)
{
	// Bullet Render
















	// 진우형 그림작품~
	/*HBRUSH bulletBrush = ::CreateSolidBrush(RGB(255, 212, 110));
	HPEN bulletPen = ::CreatePen(PS_SOLID, 1, RGB(255, 212, 110));
	
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, bulletBrush);
	HPEN oldPen = (HPEN)::SelectObject(_hdc, bulletPen);

	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::SelectObject(_hdc, oldPen);

	::DeleteObject(bulletBrush);
	::DeleteObject(bulletPen);*/
}

void CBullet::Release()
{
}

void CBullet::Update_Dir()
{
}
