#include "pch.h"
#include "Zombie.h"

CZombie::CZombie()
{

}

CZombie::~CZombie()
{
	Release();
}

void CZombie::Initialize()
{
	// CZombie Initialize
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	// CZombie Update
	
	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{

}

void CZombie::Render(HDC _hdc)
{




	/*HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(oldBrush);*/
}

void CZombie::Release()
{

}

void CZombie::Dir_Update()
{
}
