#include "pch.h"
#include "SceneMgr.h"
#include "Turret.h"
#include "MainGame.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CZombieMgr.h"
#include "ItemMgr.h"
#include "ComboMgr.h"
#include "MainGameScene.h"

CMainGameScene::CMainGameScene() : m_dwTime(GetTickCount()), m_iFps(0), m_bStageClear(true), m_bPortalExisted(false)
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


	CZombieMgr::Set_Light_Zombie_Limit_Number(5);
	CZombieMgr::Set_Middle_Zombie_Limit_Number(3);
	CZombieMgr::Set_Heavy_Zombie_Limit_Number(1);
	CZombieMgr::Set_Goal_Zombies_Number(5);
	

	CComboMgr::Initialize();
	CItemMgr::Initialize();
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
	// Collision_Sphere >>> lParam : 충돌시 삭제
	// Collision_Sphere >>> wParam : 충돌시 MinusHP, HP가 0이면 사망.
	CObj* pPlayer = m_ObjList[OBJ_PLAYER].front();
	if (dynamic_cast<CPlayer*>(pPlayer)->Get_Dash() /*|| dynamic_cast<CPlayer*>(pPlayer)->Get_Barrier()*/)
	{
	}
	else
	{
		CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER]);
	}

	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 800, OBJ_LIGHT_ZOMBIE, false);
	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 500, OBJ_MIDDLE_ZOMBIE, false);
	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 200, OBJ_HEAVY_ZOMBIE, false);
	CZombieMgr::Refresh_Current_Spawn_Numbers(&m_ObjList[OBJ_ZOMBIE]);
	CItemMgr::Spawn(&m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER].front(), 2);

	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BARRIER], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collide_Bullet_With_Zombie(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Item(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Turret(m_ObjList[OBJ_TURRET], m_ObjList[OBJ_PLAYER], &m_ObjList[OBJ_ZOMBIE], &m_ObjList[OBJ_BULLET]);
	if (m_ObjList[OBJ_PLAYER].front()->IsDead())
	{
		CSceneMgr::Change_Active_Scene(SCENE_TYPE::GAME_OVER_SCENE);
	}

	if (m_ObjList[OBJ_PLAYER].size())
	{
		Vec2 vPlayerPos = m_ObjList[OBJ_PLAYER].front()->Get_Pos();
		Vec2 vPlayerDir = m_ObjList[OBJ_PLAYER].front()->Get_Dir();
		for (auto iter = m_ObjList[OBJ_ZOMBIE].begin(); iter != m_ObjList[OBJ_ZOMBIE].end(); ++iter)
		{
			static_cast<CZombie*>(*iter)->TargetPos_Update(vPlayerPos);

		}
		for (auto iter = m_ObjList[OBJ_BULLET].begin(); iter != m_ObjList[OBJ_BULLET].end(); ++iter)
		{
			static_cast<CBullet*>(*iter)->PlayerPos_Update(vPlayerPos);
			static_cast<CBullet*>(*iter)->PlayerDir_Update(vPlayerDir);
		}
	}

	for (auto iter = m_ObjList[OBJ_BULLET].begin(); iter != m_ObjList[OBJ_BULLET].end(); ++iter)
	{
		dynamic_cast<CBullet*>((*iter))->SetZombieList(&m_ObjList[OBJ_ZOMBIE]);
	}

	CComboMgr::Late_Update();

	m_bStageClear = CZombieMgr::Is_Clear_Stage();
	if (m_bStageClear && m_bPortalExisted == false)
	{
		CItemMgr::Spawn_Portal(&m_ObjList[OBJ_ITEM]);
		m_bPortalExisted = true;
	}

	if (m_bStageClear && m_bPortalExisted)
	{
		CCollisionMgr::Collide_Portal(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER]);
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

	CComboMgr::Render(_hdc);
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
