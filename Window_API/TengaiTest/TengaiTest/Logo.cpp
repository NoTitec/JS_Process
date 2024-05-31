#include "Logo.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
    Release();

}

void CLogo::Initialize()
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../ResourceImage/Loby/title.bmp", L"Logo");

}

int CLogo::Update()
{
    return 0;
}

void CLogo::Late_Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_1);
		return;
	}

}

void CLogo::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

}

void CLogo::Release()
{
}
