#include "MainGame.h"
#include "Obj.h"
#include "ObjMgr.h"
#include "Player.h"
#include "Mouse.h"
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
	srand(unsigned(time(NULL)));
	m_DC = GetDC(g_hWnd);
	//플레이어 생성
	//m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Shield(&m_ObjList[OBJ_SHIELD]);
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	//마우스 생성
	//m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, CAbstractFactory<CMouse>::Create());
	//몬스터 생성
	//m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create());
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create());

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	/*for (size_t i = 0; i < OBJ_END; ++i)
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
	}*/
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	/*for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}*/
	//몬스터 플레이어 사각형충돌검출
	//CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_PLAYER]);
	//좀비 총알 원형판정 삭제
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	//좀비 실드 충돌삭제
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_SHIELD], m_ObjList[OBJ_ZOMBIE]);
	//좀비 플레이어 접촉시 삭제
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ZOMBIE]);
	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	//좀비 생성 매니저
	//CZombieManager::Create_Zombie(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front());
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);
	CObjMgr::Get_Instance()->Render(m_DC);
	/*for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_DC);
		}
	}*/


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
	/*for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}*/

	CObjMgr::Destroy_Instance();
	ReleaseDC(g_hWnd, m_DC);
}
