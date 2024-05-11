#include "pch.h"
#include "Zombie.h"

CZombie::CZombie()
{

}

CZombie::~CZombie()
{

}

void CZombie::Initialize()
{
	m_tInfo.fCX = 40.0f;
	m_tInfo.fCY = 40.0f;	
	m_fSpeed = 5.0f;
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	float iPlayerY = m_pTarget->Get_Info().fY;
	float iPlayerX = m_pTarget->Get_Info().fX;

	float iZombieY = m_tInfo.fY;
	float iZombieX = m_tInfo.fX;
	
	float fR = std::sqrtf(((iPlayerY - iZombieY) * (iPlayerY - iZombieY)) + ((iPlayerX - iZombieX) * (iPlayerX - iZombieX)));
	
	float normalVectorY = (fR == 0) ? 0 : ((iPlayerY - iZombieY) / fR);
	float normalVectorX = (fR == 0) ? 0 : ((iPlayerX - iZombieX) / fR);

	m_tInfo.fX += (normalVectorX * m_fSpeed);
	m_tInfo.fY += (normalVectorY * m_fSpeed);

	
	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{

}

void CZombie::Render(HDC _hdc)
{
	HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(oldBrush);
}

void CZombie::Release()
{

}