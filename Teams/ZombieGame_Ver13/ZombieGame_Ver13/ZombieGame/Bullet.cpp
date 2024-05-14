#include "pch.h"
#include "Bullet.h"
#include <random>

DWORD dwTrr;

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	iTime = 0;
	iCheckTime = 0;
	Set_Scale(Vec2(20.f, 20.f));
}

int CBullet::Update()
{
	m_pZombieList;
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	// Bullet Update


	//switch (m_iType)
	//{
	//case NORMAL_GUN:
	//	break;
	//case Machine_GUN:
	//	break; 
	//case CURVE_GUN:
	//	break;
	//case BULLET_END:
	//	break;
	//default:
	//	break;
	//}

	switch (m_iType)
	{
	case 0:
		BulletType1(m_iType);
		break;
	case 1:
		BulletType2(m_iType);
		break;
	case 2:
		BulletType3(m_iType);
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

void CBullet::BulletType1(int _iType)
{
	m_tInfo.fX += m_vDir.fX * 10.f;
	m_tInfo.fY += m_vDir.fY * 10.f;
}

void CBullet::BulletType2(int _iType)
{

	iCheckTime = 30;

	if (iCheckTime > iTime > 0)
	{
		m_tInfo.fX = m_vPlayerPos.fX + 30 * m_vPlayerDir.fX;
		m_tInfo.fY = m_vPlayerPos.fY + 30 * m_vPlayerDir.fY;
		m_tInfo.fCX += 1;
		m_tInfo.fCY += 1;

	}
	else
	{

		m_tInfo.fX += 5 * m_vPlayerDir.fX;
		m_tInfo.fY += 5 * m_vPlayerDir.fY;
	}
	++iTime;
}

void CBullet::BulletType3(int _iType)
{
}


