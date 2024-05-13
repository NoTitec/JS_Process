#include "pch.h"
#include "HpBar.h"

CHpBar::CHpBar() : m_pTarget(nullptr)
{
}

CHpBar::~CHpBar()
{

}

void CHpBar::Initialize()
{

}

int CHpBar::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	Pos_Update();
	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CHpBar::Late_Update()
{

}

void CHpBar::Render(HDC _hdc)
{
	::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
	int m_iHitNumber = 3 - m_pTarget->Get_HP();
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 87, 51));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

	int m_iCurrentHpRight = m_tRect.right - (17 * m_iHitNumber);

	::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_iCurrentHpRight, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(redBrush);
}

void CHpBar::Release()
{

}

void CHpBar::Pos_Update()
{
	RECT targetRect = m_pTarget->Get_Rect();
	INFO targetInfo = m_pTarget->Get_Info();

	m_tInfo.fCX = 50.0f;
	m_tInfo.fCY = 10.0f;
	m_tInfo.fY = targetInfo.fY - targetInfo.fCY / 2.0f - 10.0f;
	m_tInfo.fX = targetInfo.fX;
}

