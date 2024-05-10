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
	m_tInfo.fCX = 10.0f;
	m_tInfo.fCY = 10.0f;

	m_fSpeed = 20.0f;
}

int CBullet::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	m_tInfo.fX += m_fSpeed * m_tInfo.fNormalX;
	m_tInfo.fY += m_fSpeed * m_tInfo.fNormalY;

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	if (m_tInfo.fX > WINCX || m_tInfo.fX < 0 || m_tInfo.fY > WINCY || m_tInfo.fY < 0)
	{
		m_bDead = true;
	}
}

void CBullet::Render(HDC _hdc)
{
	HBRUSH bulletBrush = ::CreateSolidBrush(RGB(255, 212, 110));
	HPEN bulletPen = ::CreatePen(PS_SOLID, 1, RGB(255, 212, 110));
	
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, bulletBrush);
	HPEN oldPen = (HPEN)::SelectObject(_hdc, bulletPen);

	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::SelectObject(_hdc, oldPen);

	::DeleteObject(bulletBrush);
	::DeleteObject(bulletPen);
}

void CBullet::Release()
{
}
