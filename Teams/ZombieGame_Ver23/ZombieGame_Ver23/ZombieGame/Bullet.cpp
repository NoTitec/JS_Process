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
	m_iTime = 0;
	iCheckTime = 0;
	m_bCollision = false;
	Set_Scale(Vec2(20.f, 20.f));
	m_Check_Size = false;
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
	case NORMAL_BULLET:
		BulletType1();
		break;
	case SHOTGUN_BULLET:
		BulletType2();
		break;
	case GRENADE_BULLET:
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
	HBRUSH MyBrush, OldBrush;
	MyBrush = CreateSolidBrush(RGB(255, 255, 0));
	OldBrush = (HBRUSH)SelectObject(_hdc, MyBrush);
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(_hdc, OldBrush);
	DeleteObject(MyBrush);

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
	m_tInfo.fX += m_vDir.fX * 10.f;
	m_tInfo.fY += m_vDir.fY * 10.f;
}

void CBullet::BulletType2()
{

	Check_NornalCollide();
	random_device REND;
	mt19937 DEGREE(REND());
	uniform_int_distribution<int> SETDEGREE(-10.f, 10.f);

	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	if (m_iTime == 0)
		m_fDegree = SETDEGREE(DEGREE);

	float PosDegree = atan2f(m_vDir.fY, m_vDir.fX) + 2 * PI;
	float ShotX = cos(PosDegree + m_fDegree * PI / 180.f);
	float ShotY = sin(PosDegree + m_fDegree * PI / 180.f);

	m_tInfo.fX = m_tInfo.fX + 30.f * ShotX;
	m_tInfo.fY = m_tInfo.fY + 30.f * ShotY;

	++m_iTime;
}

void CBullet::BulletType3()
{
	
	Check_WallCollide();
	if (m_bCollision == true)
	{
		//m_fSpeed = m_fSpeed / 1.3f;
		m_bCollision = false;
	}
	m_fSpeed -= 0.15f;


	if (m_fSpeed < 0)
	{
		m_fSpeed = -1.f;
		m_bCheckSpeed = true;
		++m_iTime;
		if (m_Check_Size == false && m_iTime < 100)
		{
			if (m_tInfo.fCX < 151)
			{
				if (m_Check_Size == false)
				{
					m_tInfo.fCX += 5;
					m_tInfo.fCY += 5;
					if(m_tInfo.fCX > 140)
						m_Check_Size = true;
				}
				else
				{
					//m_Check_Size = true;
				}
			}
		}
		else if (m_Check_Size == true && m_iTime < 35)
		{
			if(10 < m_tInfo.fCX)
			m_tInfo.fCX -= 10;
			m_tInfo.fCY -= 10;
			m_Check_Size = true;
		}
		else if (m_iTime > 35)
		{
			m_bDead = true;
		}
	}
	else if (m_fSpeed >= 0)
	{
		if (m_iTime > 100)
		{
			m_tInfo.fX += m_vDir.fX * 5;
			m_tInfo.fY += m_vDir.fY * 5;
		}
		else if (m_iTime >= 0 && m_iTime < 100)
		{
			m_tInfo.fX += m_vDir.fX * m_fSpeed;
			m_tInfo.fY += m_vDir.fY * m_fSpeed;
		}
	}
	
}

void CBullet::Check_WallCollide()
{
	if (m_tInfo.fX < 10 || m_tInfo.fX > 790)
	{
		m_bCollision = true;
		m_vDir.fX *= -1.0f;
	}
	else if (m_tInfo.fY < 10 || m_tInfo.fY >590)
	{
		m_bCollision = true;
		m_vDir.fY *= -1.0f;
	}
}

void CBullet::Check_NornalCollide()
{
	if (m_tInfo.fX < 10 || m_tInfo.fX > 790)
	{
		m_bDead = true;
	}
	else if (m_tInfo.fY < 10 || m_tInfo.fY >590)
	{
		m_bDead = true;
	}
}
bool CBullet::Check_Speed()
{
	return m_bCheckSpeed;
}


