#include "pch.h"
#include "BossHpBar.h"
#include "BossZombie.h"

CBossHpBar::CBossHpBar()
{
}

CBossHpBar::~CBossHpBar()
{
}

void CBossHpBar::Initialize()
{
	Pos_Update();
}

int CBossHpBar::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CBossHpBar::Late_Update()
{
}

void CBossHpBar::Render(HDC _hdc)
{
	::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	HFONT nameFont = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±Ã¼­"));
	HFONT oldNameFont = (HFONT)::SelectObject(_hdc, nameFont);
	::SetBkMode(_hdc, TRANSPARENT);
	::SetTextColor(_hdc, RGB(255, 49, 49));
	::TextOut(_hdc, m_tInfo.fX - 100, m_tInfo.fY - 68, L"±è³²¿µ Á»ºñ", 6);
	::SetTextColor(_hdc, RGB(0, 0, 0));
	::SetBkMode(_hdc, OPAQUE);
	::SelectObject(_hdc, oldNameFont);
	::DeleteObject(nameFont);

	int iTargetFullHp = static_cast<CBossZombie*>(m_pTarget)->Get_Full_Hp();

	int iCurrentHit = iTargetFullHp - m_pTarget->Get_HP();
	int iCurrentRight = m_tRect.right - (iCurrentHit * (m_tInfo.fCX / iTargetFullHp));

	HBRUSH redBrush = (HBRUSH)::CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);
	::Rectangle(_hdc, m_tRect.left, m_tRect.top, iCurrentRight, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(redBrush);

	TCHAR szHpAlert[32];
	wsprintf(szHpAlert, L"%d / %d", m_pTarget->Get_HP(), iTargetFullHp);

	HFONT hpFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±Ã¼­"));
	HFONT oldHpFont = (HFONT)::SelectObject(_hdc, hpFont);
	::SetBkMode(_hdc, TRANSPARENT);
	::TextOut(_hdc, m_tInfo.fX - 25, m_tInfo.fY - 10, szHpAlert, wcslen(szHpAlert));
	::SetBkMode(_hdc, OPAQUE);
	::SelectObject(_hdc, oldHpFont);
	::DeleteObject(hpFont);
}

void CBossHpBar::Release()
{
}

void CBossHpBar::Pos_Update()
{
	m_tInfo.fX = WINCX / 2.0f;
	m_tInfo.fY = WINCY / 6.0f - 20;
	m_tInfo.fCX = 600.0f;
	m_tInfo.fCY = 30.0f;
}
