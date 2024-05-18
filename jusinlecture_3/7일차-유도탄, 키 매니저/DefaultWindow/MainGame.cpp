#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"

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

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	
	//for (int i = 0; i < 7; ++i)
	//{
	//	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(float(rand() % WINCX), float(rand() % WINCY)));
	//}

	CLineMgr::Get_Instance()->Initialize();

	//플레이어 맴버변수 linelist에 linemgr이 가진 선들 리스트 포인터 넘겨주기
	CObj* player = CObjMgr::Get_Instance()->Get_Player();
	static_cast<CPlayer*>(player)->Set_LinePointer(CLineMgr::Get_Instance()->Get_LineList());
}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	CKeyMgr::Get_Instance()->Key_Update();
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	CLineMgr::Get_Instance()->Render(m_DC);
	CObjMgr::Get_Instance()->Render(m_DC);
	
	
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
	CKeyMgr::Destroy_Instance();
	CLineMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);	
}
