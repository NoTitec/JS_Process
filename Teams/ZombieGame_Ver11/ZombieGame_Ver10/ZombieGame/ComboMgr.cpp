#include "pch.h"
#include "ComboMgr.h"

bool CComboMgr::bComboTime = false;
bool CComboMgr::bHit = false;
DWORD CComboMgr::dw_comboTime = 0;
int CComboMgr::iComboNumber = 0;
int CComboMgr::iLastingTime = 5000;
TCHAR CComboMgr::sz_Combo[32] = { 0, };

void CComboMgr::Initialize()
{
	dw_comboTime = GetTickCount();
	
}

void CComboMgr::Late_Update()
{
	if (bComboTime == true)
	{
		if (bHit)
		{
			++iComboNumber;
			dw_comboTime = GetTickCount();
		}
		else
		{
			if (dw_comboTime + iLastingTime < GetTickCount())
			{
				iComboNumber = 0;
				dw_comboTime = 0;
				bComboTime = false;
			}
		}
	}
	else
	{
		if (bHit)
		{
			++iComboNumber;
			bComboTime = true;
			dw_comboTime = GetTickCount();
		}
	}
	bHit = false;
}

void CComboMgr::Render(HDC _hdc)
{
	if (bComboTime == true)
	{
		wsprintf(sz_Combo, L"COMBO %d", iComboNumber);
		HFONT comboFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±Ã¼­"));
		HFONT oldComboFont = (HFONT)::SelectObject(_hdc, comboFont);
		SetBkMode(_hdc, TRANSPARENT);
		SetTextColor(_hdc, RGB(255, 49, 49));
		TextOut(_hdc, WINCX / 2.0f - 100, 25, sz_Combo, lstrlen(sz_Combo));
		SetTextColor(_hdc, RGB(0, 0, 0));
		SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, comboFont);
		::DeleteObject(oldComboFont);

	}
}

void CComboMgr::Hit()
{
	bHit = true;
}