#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 80.f;
	m_tInfo.fCY = 80.f;

	m_fSpeed = 3.f;
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

	//fWidth  = m_pTarget->Get_Info().fX - m_tInfo.fX;
	//fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	//fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	//// fWidth / fDiagonal == cos(m_fAngle)

	//fRadian = acos(fWidth / fDiagonal);

	//if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//	fRadian = 2 * PI - fRadian;

	//// radian to degree
	//m_fAngle = fRadian * 180.f / PI;

	///*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//	m_fAngle *= -1.f;*/

	//// degree to radian
	//m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
	//m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	/*if (WINCX <= m_tRect.right || 0 >= m_tRect.left)
		m_fSpeed *= -1.f;*/
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}
