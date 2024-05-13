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
	Set_Scale(Vec2(30.f, 30.f));
}

int CBullet::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	// Bullet Update
	
	switch (m_iType)
	{
	case 0:
		BulletType1();
		break;
	case 1:
		BulletType2();
		break;
	case 2:
		BulletType3();
		break;


	default:
		break;
	}
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
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);


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

void CBullet::BulletType1()
{
	Vec2 vPos = Get_Pos();
	Vec2 vDir = Get_Dir();
	Set_Speed(10.f);
	float vSpeed = Get_Speed();

	vPos.fX += vSpeed * vDir.fX;
	vPos.fY += vSpeed * vDir.fY;

	Set_Pos(vPos);
}

void CBullet::BulletType2()
{
}

void CBullet::BulletType3()
{
}

