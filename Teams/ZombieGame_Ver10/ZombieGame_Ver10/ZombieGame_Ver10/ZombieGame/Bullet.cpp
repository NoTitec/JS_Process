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
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(-50, 50);

	if (iTime == 0)
		m_fDegree = dis(gen);


	float PosDegree = atan2f(m_vDir.fY, m_vDir.fX) + 2 * PI;
	float ShotX = cos(PosDegree + m_fDegree * PI / 180);
	float ShotY = sin(PosDegree + m_fDegree * PI / 180);

	m_tInfo.fX = m_tInfo.fX + 5 * ShotX;
	m_tInfo.fY = m_tInfo.fY + 5 * ShotY;
	++iTime;

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


