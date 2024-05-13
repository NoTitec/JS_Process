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
    m_tInfo.fCX = 10.f;
    m_tInfo.fCY = 10.f;

    m_fSpeed = 12.f;
}

int CBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));

	/*switch (m_eDir)
	{
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;

	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;

	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	}*/

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right ||
		100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

RECT* CBullet::Get_Rect_Pointer()
{
	return &m_tRect;;
}
