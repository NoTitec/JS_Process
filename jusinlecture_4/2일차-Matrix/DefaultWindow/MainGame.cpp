#include "stdafx.h"
#include "MainGame.h"
#include "KeyMgr.h"

CMainGame::CMainGame() : m_pPlayer(nullptr), m_pMonster(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{

	m_DC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	/*if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}

	dynamic_cast<CMonster*>(m_pMonster)->Set_Player(m_pPlayer);*/
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	//m_pMonster->Update();
	CKeyMgr::Get_Instance()->Key_Update();
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);
	//m_pMonster->Render(m_DC);
}

void CMainGame::Release()
{
	//Safe_Delete<CObj*>(m_pMonster);
	Safe_Delete<CObj*>(m_pPlayer);
	CKeyMgr::Destroy_Instance();
	ReleaseDC(g_hWnd, m_DC);

	
}
