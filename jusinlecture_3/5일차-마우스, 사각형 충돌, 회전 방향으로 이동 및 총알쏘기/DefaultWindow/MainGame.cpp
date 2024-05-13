#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Monster.h"
#include "Mouse.h"

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
	
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Shield(&m_ObjList[OBJ_SHIELD]);

	// ����
	for (int i = 0; i < 5; ++i)
	{
		m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create(float(rand() % WINCX), float(rand() % WINCY)));
	}

	// ���콺

	m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create());

}

void CMainGame::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
		
}

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}

	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_MOUSE], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_DC);
		}
	}


	// ��Ʈ ���

	TCHAR	szBuf[32] = L"";

	// wsprintf : �Ҽ��� �ڸ����� ��� �Ұ���, winapi ���̺귯������ ����
	wsprintf(szBuf, L"Bullet : %d", m_ObjList[OBJ_BULLET].size());
	
	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ ���̺귯������ ����(��� ���� ���ڸ� ����)
	TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));


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

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}


	ReleaseDC(g_hWnd, m_DC);

	
}
