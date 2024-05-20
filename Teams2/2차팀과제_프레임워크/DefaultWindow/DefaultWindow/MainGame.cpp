#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "RenderMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

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

	SCENE.Initialize();
	RENDER.Init();
}

void CMainGame::Update()
{
	OBJ.Update();
	SCENE.Update();
}

void CMainGame::Late_Update()
{
	SCENE.Late_Update();
	KEY.Key_Update();
}

void CMainGame::Render()
{
	//++m_iFps;
	static PAINTSTRUCT ps{};
	BeginPaint(g_hWnd, &ps);
	RENDER.BeginRender();
	OBJ.Render(m_DC);
	SCENE.Render(m_DC);
	RENDER.EndRender();

	EndPaint(g_hWnd, &ps);
	/*Rectangle(m_DC, 0, 0, WINCX, WINCY);
	OBJ.Render(m_DC);
	

	SCENE.Render(m_DC);*/
	
	/*if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFps);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFps = 0;
		m_dwTime = GetTickCount();
	}*/
}

void CMainGame::Release()
{
	CLineMgr::Destroy_Instance();


	ReleaseDC(g_hWnd, m_DC);	
}
