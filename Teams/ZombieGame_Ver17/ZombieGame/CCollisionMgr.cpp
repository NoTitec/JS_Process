#include "pch.h"
#include "CCollisionMgr.h"
#include "Turret.h"
#include "CItem.h"
#include "Player.h"
#include "Zombie.h"
#include "ItemMgr.h"
#include "CKeyMgr.h"
#include "CZombieMgr.h"
#include "ComboMgr.h"
#include "SceneMgr.h"


CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{

}



void CCollisionMgr::Collide_Portal(list<CObj*> _itemList, list<CObj*> _playerList)
{
	for (auto& item : _itemList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(item, player))
			{
				if (OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != item->Get_type())
				{
					continue;
				}
				CSceneMgr::Change_Active_Scene(SCENE_TYPE::BOSS_GAME_SCENE);
			}
		}
	}
}


void CCollisionMgr::Collide_Turret(list<CObj*> _turretList, list<CObj*> _playerList, list<CObj*>* _zombieList, list<CObj*>* _bulletList)
{
	for (auto& turret : _turretList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(turret, player))
			{
				if (KEY_TAP(KEY::E))
				{
					static_cast<CTurret*>(turret)->Set_Build();
					static_cast<CTurret*>(turret)->Set_SurviveTime();
					static_cast<CTurret*>(turret)->Set_DeadTime();
					static_cast<CTurret*>(turret)->Set_ZombieList(_zombieList);
					static_cast<CTurret*>(turret)->Set_BulletList(_bulletList);
				}
			}
		}
	}
}



void CCollisionMgr::Collide_Boss_With_Player(list<CObj*> _bossList, list<CObj*> _playerList)
{
	for (auto& boss : _bossList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(boss, player))
			{
				player->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::Collide_Item(list<CObj*> _itemList, list<CObj*> _playerList)
{
	for (auto& item : _itemList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(item, player))
			{
				item->Set_Dead();
				CItemMgr::Set_Create_Item_Time(GetTickCount());

				switch (static_cast<CItem*>(item)->Get_Item_Type())
				{
				case OBJ_ITEM_TYPE::OBJ_ITEM_DRUG:
				{
					if (static_cast<CPlayer*>(player)->Get_HP() < 10)
					{
						player->Set_HP(player->Get_HP() + 1);
					}
					break;
				}
				case OBJ_ITEM_TYPE::OBJ_ITEM_BARRIER:
				{
					static_cast<CPlayer*>(player)->Set_Barrier();
					break;
				}
				}
			}
		}
	}
}
void CCollisionMgr::Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				CComboMgr::Hit();
				if (Src->Get_HP() <= 1)
				{
					Dst->Set_Dead();
					Src->Set_Dead();
					CZombieMgr::Kill_Zombie();
				}
				else
				{
					Dst->Set_Dead();
					Src->MinusHP();
					dynamic_cast<CZombie*>(Src)->Set_Speed_Zero();
				}
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj* _Dst, CObj* _Src)
{
	float fDiffY = _Dst->Get_Info().fY - _Src->Get_Info().fY;
	float fDiffX = _Dst->Get_Info().fX - _Src->Get_Info().fX;
	
	float fR = std::sqrtf((fDiffY * fDiffY) + (fDiffX * fDiffX));
	float fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	return fRadius >= fR;
}
