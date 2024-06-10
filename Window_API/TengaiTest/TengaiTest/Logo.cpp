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
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../ResourceImage/Loby/FreeBirdMain.bmp", L"Logo");
	m_hVideo = MCIWndCreate(g_hWnd,		// 부모 윈도우 핸들
		nullptr,	// 인스턴스 핸들
		WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR,	// 윈도우 모양 설정
		L"../Video/Tengai_intro.wmv");		// 재생할 파일의 경로

	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	MCIWndPlay(m_hVideo);

	/*CUI* pStartButton = CAbstractFactory<CStartButton>::Create_UI(650.f,50.f);
	pStartButton->Set_FrameKey(L"StartButton");
	UIMgr->Add_UI(UI_MENU, pStartButton);*/
	//SoundMgr->PlayBGM(L"freebirdsolo.mp3", 0.3f);
}

int CLogo::Update()
{
	//UIMgr->Update();
    return 0;
}

void CLogo::Late_Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_MENU);
		return;
	}
	//UIMgr->Late_Update();
}

void CLogo::Render(HDC hDC)
{
	//HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	//BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	//UIMgr->Render(hDC);
}

void CLogo::Release()
{
	MCIWndClose(m_hVideo);
	//UIMgr->Delete_ID(UI_MENU);
	//SoundMgr->StopSound(SOUND_BGM);
}
