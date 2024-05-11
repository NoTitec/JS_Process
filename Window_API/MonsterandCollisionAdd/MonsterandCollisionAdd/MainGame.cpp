#include "MainGame.h"
#include "Obj.h"
#include "Player.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include "CollisionManager.h"
#include "ZombieManager.h"

CMainGame::CMainGame() :m_dwTime(GetTickCount64()), m_iFps(0)
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
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);
	//m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create());
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

	//몬스터 총알 원형판정 삭제
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	//몬스터 플레이어 접촉시 삭제
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ZOMBIE]);
	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CZombieManager::Create_Zombie(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front());
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_DC);
		}
	}

	// 폰트 출력
	TCHAR	szBuf[32] = L"";

	// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	wsprintf(szBuf, L"Bullet : %d", (int)m_ObjList[OBJ_BULLET].size());

	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ 라이브러리에서 제공(모든 서식 문자를 지원)
	TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));


	// 1. dc 
	// 2-3. x,y 좌표
	// 4. 문자열 버퍼의 첫 주소
	// 5. 문자열 버퍼의 크기

	// RECT	rc{ 100, 100, 200, 200 };
	// lstrcpy(szBuf, L"Jusin");
	// DrawText(m_DC, szBuf, lstrlen(szBuf), &rc, DT_CENTER);

	// fps 출력

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFps);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFps = 0;
		m_dwTime = GetTickCount64();
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
