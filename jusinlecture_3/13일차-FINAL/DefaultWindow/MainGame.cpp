#include "stdafx.h"
#include "MainGame.h"

#include "SceneMgr.h"

#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "TileMgr.h"
#include "SoundMgr.h"

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

	m_DC = GetDC(g_hWnd);

	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_LOGO);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");	

	CSoundMgr::Get_Instance()->Initialize();

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
}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{

	CSceneMgr::Get_Instance()->Late_Update();	
	CKeyMgr::Get_Instance()->Key_Update();
	CScrollMgr::Get_Instance()->Scroll_Lock();
}

void CMainGame::Render()
{
	++m_iFps;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFps);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFps = 0;
		m_dwTime = GetTickCount();
	}

	if (CSceneMgr::SC_LOGO == CSceneMgr::Get_Instance()->Get_SceneID())
		return;

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");
	CSceneMgr::Get_Instance()->Render(hMemDC);

	BitBlt(m_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);		

}

void CMainGame::Release()
{
#ifdef _DEBUG

	FreeConsole();

#endif // _DEBUG

	CSoundMgr::Destroy_Instance();
	CTileMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CLineMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);	
}
