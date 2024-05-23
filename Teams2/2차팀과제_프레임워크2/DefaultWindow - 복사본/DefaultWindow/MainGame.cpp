#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"

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
	BMP.Insert_Bmp(L"../Image/Back.bmp", L"Back");
	SCENE.Initialize();

}

void CMainGame::Update()
{
	OBJ.Update();
	SCENE.Update();
}

void CMainGame::Late_Update()
{
	OBJ.Late_Update();
	SCENE.Late_Update();
	KEY.Key_Update();
}

void CMainGame::Render()
{
	m_hMemDC = BMP.Find_Img(L"Back");

	SCENE.Render(m_hMemDC);
	OBJ.Render(m_hMemDC);

	BitBlt(m_DC, 0, 0, WINCX, WINCY, m_hMemDC, 0, 0, SRCCOPY);

	
	++m_iFps;
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
	CLineMgr::Destroy_Instance();


	ReleaseDC(g_hWnd, m_DC);	
}
