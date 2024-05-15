#pragma once
class CComboMgr
{
public:
	static void Initialize();
	static void Late_Update();
	static void Render(HDC _hdc);
	static void Hit();
public:
	static int iLastingTime;

	static bool bHit;
	static bool bComboTime;
	static DWORD dw_comboTime;
	static int iComboNumber;

	static TCHAR sz_Combo[32];
	
};

