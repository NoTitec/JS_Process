#include "pch.h"
#include "BossGameScene.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "CZombieMgr.h"
#include "ComboMgr.h"
#include "Zombie.h"
#include "Bullet.h"
#include "CCollisionMgr.h"
#include "SceneMgr.h"
#include "BossZombie.h"
#include "Turret.h"

CBossGameScene::CBossGameScene()
{

}

CBossGameScene::~CBossGameScene()
{
	Release();
}

void CBossGameScene::Initialize()
{
	m_DC = GetDC(g_hWnd);
	m_ObjList[OBJ_ID::OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create(WINCX / 2.0f, WINCY / 2.0f + 150));
	m_ObjList[OBJ_ID::OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(250, 450));
	m_ObjList[OBJ_ID::OBJ_TURRET].push_back(CAbstractFactory<CTurret>::Create(550, 450));
	m_ObjList[OBJ_ID::OBJ_BOSS_ZOMBIE].push_back(CAbstractFactory<CBossZombie>::Create());
	CObj* pBoss = m_ObjList[OBJ_ID::OBJ_BOSS_ZOMBIE].front();

	dynamic_cast<CBossZombie*>(pBoss)->Set_Target_Pos(m_ObjList[(UINT)OBJ_ID::OBJ_PLAYER].front()->Get_Pos());

	static_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);
	static_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BarrierList(&m_ObjList[OBJ_BARRIER]);

	m_iStage = STAGE_STATE::FIRST_STAGE;
	CZombieMgr::Set_Light_Zombie_Limit_Number(2);
	CZombieMgr::Set_Middle_Zombie_Limit_Number(2);
	CZombieMgr::Set_Heavy_Zombie_Limit_Number(2);

	CComboMgr::Initialize();
}

int CBossGameScene::Update()
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

void CBossGameScene::Late_Update()
{
	// TargetPos Update()
	CObj* pBoss = m_ObjList[(UINT)OBJ_ID::OBJ_BOSS_ZOMBIE].front();
	dynamic_cast<CBossZombie*>(pBoss)->Set_Target_Pos(m_ObjList[(UINT)OBJ_ID::OBJ_PLAYER].front()->Get_Pos());

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

	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BARRIER], m_ObjList[OBJ_ZOMBIE]);

	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BOMB], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Item(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Turret(m_ObjList[OBJ_TURRET], m_ObjList[OBJ_PLAYER], &m_ObjList[OBJ_ZOMBIE], &m_ObjList[OBJ_BULLET]);
	CCollisionMgr::Collide_Boss_With_Player(m_ObjList[OBJ_BOSS_ZOMBIE], m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collide_Bullet_With_Zombie(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);

	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 800, OBJ_LIGHT_ZOMBIE, true);
	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 500, OBJ_MIDDLE_ZOMBIE, true);
	CZombieMgr::Spawn(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front(), 200, OBJ_HEAVY_ZOMBIE, true);
	CZombieMgr::Refresh_Current_Spawn_Numbers(&m_ObjList[OBJ_ZOMBIE]);

	CCollisionMgr::Collide_Bullet(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_BOSS_ZOMBIE]);
	CCollisionMgr::Collide_Bullet(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collide_Bullet_Player(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_PLAYER]);
	
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
}

void CBossGameScene::Render(HDC _hdc)
{
	::Rectangle(_hdc, 0, 0, WINCX, WINCY);
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

void CBossGameScene::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
	ReleaseDC(g_hWnd, m_DC);
}
