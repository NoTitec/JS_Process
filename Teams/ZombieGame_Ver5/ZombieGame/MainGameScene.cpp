#include "pch.h"
#include "SceneMgr.h"
#include "Turret.h"
#include "MainGame.h"
#include "Player.h"
#include "Zombie.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CZombieMgr.h"
#include "ItemMgr.h"
#include "MainGameScene.h"

CMainGameScene::CMainGameScene() : m_dwTime(GetTickCount()), m_iFps(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGameScene::~CMainGameScene()
{
	Release();
}

void CMainGameScene::Initialize()
{
	m_DC = GetDC(g_hWnd);
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());

	m_ObjList[OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(250, 150));
	m_ObjList[OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(250, 450));
	m_ObjList[OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(550, 150));
	m_ObjList[OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(550, 450));

	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BarrierList(&m_ObjList[OBJ_BARRIER]);
}

int CMainGameScene::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();
			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
	return 0;
}

void CMainGameScene::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Item(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Turret(m_ObjList[OBJ_TURRET], m_ObjList[OBJ_PLAYER], &m_ObjList[OBJ_ZOMBIE], &m_ObjList[OBJ_BULLET]);
	
	
		CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 5, 800, OBJ_LIGHT_ZOMBIE);
	
		CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 3, 500, OBJ_MIDDLE_ZOMBIE);
	
		CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 1, 200, OBJ_HEAVY_ZOMBIE);
	
	
	CItemMgr::Create_Item(&m_ObjList[OBJ_ITEM]);

	if (m_ObjList[OBJ_PLAYER].front()->IsDead())
	{
		CSceneMgr::Change_Active_Scene(2);
	}


	//////////////////////////////////////////////
	Vec2 vPlayerPos = m_ObjList[OBJ_PLAYER].front()->Get_Pos();
	for (auto iter = m_ObjList[OBJ_ZOMBIE].begin(); iter != m_ObjList[OBJ_ZOMBIE].end(); ++iter)
	{
		static_cast<CZombie*>(*iter)->TargetPos_Update(vPlayerPos);
		// 이거 코드 문제 있으면 말해주세요 >> 좀비쪽에서 문제없이 좌표 잘 받아진다면,
		// static_cast로 변경해주세요.
		// ZombieMgr쪽 코드 해결바람.
	}
	

}

void CMainGameScene::Render(HDC _hdc)
{
	++m_iFps;
	::Rectangle(m_DC, 0, 0, WINCX, WINCY);

	//HBRUSH greyBrush = CreateSolidBrush(RGB(127, 125, 119));
	HBRUSH greenBrush = CreateSolidBrush(RGB(144, 215, 86));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(m_DC, greenBrush);
	::Rectangle(m_DC, 0, 0, WINCX, WINCY);
	::SelectObject(m_DC, oldBrush);
	::DeleteObject(greenBrush);

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_DC);
		}
	}
}

void CMainGameScene::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
	ReleaseDC(g_hWnd, m_DC);
}
