#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"

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

	m_DC = GetDC(g_hWnd);

#pragma region ����
	/*if (!m_pPlayer)
	{
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
	}*/
	// m_pPlayer = CAbstractFactory<CPlayer>::Create();
	// 
	// dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
#pragma endregion ����

	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);

}

void CMainGame::Update()
{
	// m_pPlayer->Update();
	// 
	// for (auto iter = m_BulletList.begin(); iter != m_BulletList.end(); )
	// {
	// 	int iResult = (*iter)->Update();
	// 
	// 	if (OBJ_DEAD == iResult)
	// 	{
	// 		Safe_Delete<CObj*>(*iter);
	// 		iter = m_BulletList.erase(iter);
	// 	}
	// 	else
	// 		++iter;
	// }

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
	/*m_pPlayer->Late_Update();

	for (auto& pBullet : m_BulletList)
		pBullet->Late_Update();*/

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}

	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);

	/*m_pPlayer->Render(m_DC);

	for (auto& pBullet : m_BulletList)
		pBullet->Render(m_DC);*/

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


	// 1. dc 
	// 2-3. x,y ��ǥ
	// 4. ���ڿ� ������ ù �ּ�
	// 5. ���ڿ� ������ ũ��

	// RECT	rc{ 100, 100, 200, 200 };
	// lstrcpy(szBuf, L"Jusin");
	// DrawText(m_DC, szBuf, lstrlen(szBuf), &rc, DT_CENTER);

	// fps ���

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
	// Safe_Delete<CObj*>(m_pPlayer);
	// 
	// for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	// m_BulletList.clear();

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}


	ReleaseDC(g_hWnd, m_DC);

	
}
