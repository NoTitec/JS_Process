#include "stdafx.h"
#include "MainGame.h"
#include "KeyMgr.h"
#include "Player.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ColMgr.h"

CMainGame* CMainGame::m_pInstance = nullptr;

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);
	m_HWND = g_hWnd;
	SCENEMGR->Scene_Change(CSceneMgr::SC_SUN);

	{
		m_BackDC = CreateCompatibleDC(m_DC);
		m_hBitmap = CreateCompatibleBitmap(m_DC, WINCX, WINCY);
		m_hOldBitmap = (HBITMAP)SelectObject(m_BackDC, m_hBitmap);
	}
	
	if (!m_DC || !m_BackDC || !m_hBitmap || !m_hOldBitmap)
	{
		MessageBox(m_HWND, L"Failed to initialize double buffering", L"Error", MB_OK);
	}
}

void CMainGame::Update()
{
	SCENEMGR->Update();
	KEYMGR->Key_Update();
}

void CMainGame::Late_Update()
{
	SCENEMGR->Late_Update();
}

void CMainGame::Render()
{
	PatBlt(m_BackDC, 0, 0, WINCX, WINCY, WHITENESS);
	SCENEMGR->Render(m_BackDC);
	BitBlt(m_DC, 0, 0, WINCX, WINCY, m_BackDC, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	COLMGR->Destroy_Instance();
	OBJMGR->Destroy_Instance();
	SCENEMGR->Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);

	// SelectObject(m_BackDC, m_hOldBitmap);
	// DeleteObject(m_hBitmap);
	// DeleteDC(m_BackDC);
}
