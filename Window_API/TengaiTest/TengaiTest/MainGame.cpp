#include "MainGame.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
CMainGame::CMainGame() :m_dwTime(GetTickCount()), m_iFps(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));

}

CMainGame::~CMainGame()
{
	Release();

}

void CMainGame::Initialize()
{
	srand(unsigned(time(NULL)));

#ifdef _DEBUG

	if (::AllocConsole() == TRUE)
	{
		FILE* nfp[3];
		freopen_s(nfp + 0, "CONOUT$", "rb", stdin);
		freopen_s(nfp + 1, "CONOUT$", "wb", stdout);
		freopen_s(nfp + 2, "CONOUT$", "wb", stderr);
		std::ios::sync_with_stdio();
	}

#endif // _DEBUG

	m_DC = GetDC(g_hWnd);
	SceneMgr->Scene_Change(CSceneMgr::SC_LOGO);

#pragma region 이미지 삽입구문들
	BmpMgr->Insert_Bmp(L"../ResourceImage/Back.bmp", L"Back");
	BmpMgr->Insert_Bmp(L"../ResourceImage/Player(Miko)/ForwardMove/Miko_Fly_Forward.bmp",L"Miko_Fly_Forward");
	BmpMgr->Insert_Bmp(L"../ResourceImage/Player(Miko)/BackMove/Miko_Fly_Backward.bmp",L"Miko_Fly_Backward");
	BmpMgr->Insert_Bmp(L"../ResourceImage/PlayerAttack/MikoBasicAttack.bmp",L"MikoBasicAttack");

	BmpMgr->Insert_Bmp(L"../ResourceImage/Boss/GreenBoss_Idle.bmp",L"GreenBoss_Idle");
	BmpMgr->Insert_Bmp(L"../ResourceImage/Item/PowerItem.bmp",L"PowerItem");
	BmpMgr->Insert_Bmp(L"../ResourceImage/UI/GameStartButton/StartButton.bmp", L"StartButton");
	BmpMgr->Insert_Bmp(L"../ResourceImage/UI/PowerGetAndLose/PowerUp.bmp",L"PowerUp");
#pragma endregion
}

void CMainGame::Update()
{
	SceneMgr->Update();
}

void CMainGame::Late_Update()
{
	SceneMgr->Late_Update();
	KeyMgr->Key_Update();
	ScrollMgr->Scroll_Lock();
}

void CMainGame::Render()
{
	++m_iFps;

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");
	SceneMgr->Render(hMemDC);

	BitBlt(m_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFps);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFps = 0;
		m_dwTime = GetTickCount();
	}

}

void CMainGame::Release()
{
#ifdef _DEBUG

	FreeConsole();

#endif // _DEBUG
	CBmpMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	ReleaseDC(g_hWnd, m_DC);

}
