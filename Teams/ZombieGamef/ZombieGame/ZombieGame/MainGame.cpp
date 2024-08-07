#include "pch.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "CKeyMgr.h"
//#include "Player.h"
//#include "Zombie.h"
//#include "AbstractFactory.h"
//#include "CCollisionMgr.h"
//#include "CZombieMgr.h"
//#include "ItemMgr.h"


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

	// Manager Initialize
	CKeyMgr::GetInstance()->Initialize();
	CSceneMgr::Initialize();
}

void CMainGame::Update()
{	
	// Manager Update
	CKeyMgr::GetInstance()->Update();
	CSceneMgr::Update();
}

void CMainGame::Late_Update()
{
	CSceneMgr::Late_Update();
}

void CMainGame::Render()
{
	CSceneMgr::Render(m_DC);
}

void CMainGame::Release()
{
	CSceneMgr::Release();
	ReleaseDC(g_hWnd, m_DC);
}
