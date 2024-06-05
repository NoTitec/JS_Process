#include "Logo.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "AbstractFactory.h"
#include "UIMgr.h"
#include "StartButton.h"
#include "SceneMgr.h"
#include "SoundMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
    Release();

}

void CLogo::Initialize()
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../ResourceImage/Loby/FreeBirdMain.bmp", L"Logo");
	CUI* pStartButton = CAbstractFactory<CStartButton>::Create_UI(650.f,50.f);
	pStartButton->Set_FrameKey(L"StartButton");
	UIMgr->Add_UI(UI_MENU, pStartButton);
	SoundMgr->PlayBGM(L"freebirdsolo.mp3", 1.f);
}

int CLogo::Update()
{
	UIMgr->Update();
    return 0;
}

void CLogo::Late_Update()
{
	/*if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_1);
		return;
	}*/
	UIMgr->Late_Update();
}

void CLogo::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	UIMgr->Render(hDC);
}

void CLogo::Release()
{
	UIMgr->Delete_ID(UI_MENU);
	SoundMgr->StopSound(SOUND_BGM);
}
