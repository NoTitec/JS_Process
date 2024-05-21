#include "stdafx.h"
#include "MainGame.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"


CMainGame::CMainGame() : m_pPlayer(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{

	m_DC = GetDC(g_hWnd);


	CLineMgr::Get_Instance()->Initialize();
}

void CMainGame::Update()
{
	CLineMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CKeyMgr::Get_Instance()->Key_Update();
	CLineMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);


	CLineMgr::Get_Instance()->Render(m_DC);
}

void CMainGame::Release()
{
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CLineMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);

	
}
