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
#include "Bullet.h"

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
				if (OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != item->Get_Type())
				{
					continue;
				}
				CSceneMgr::Change_Active_Scene(SCENE_TYPE::BOSS_ENTRANCE_SCENE);
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

void CCollisionMgr::Collide_Bullet_Item(list<CObj*> _bulletItemList, list<CObj*> _playerList)
{
	for (auto& bulletItem : _bulletItemList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(bulletItem, player))
			{
				bulletItem->Set_Dead();
				BULLET_TYPE eBulletType = (BULLET_TYPE)bulletItem->Get_Type();

				switch (eBulletType)
				{
				case BULLET_TYPE::NORMAL_BULLET:
				{
					static_cast<CPlayer*>(player)->Set_BulletCount(30);
					player->Set_Type(BULLET_TYPE::NORMAL_BULLET);
					break;
				}
				case BULLET_TYPE::SHOTGUN_BULLET:
				{
					static_cast<CPlayer*>(player)->Set_BulletCount(30);
					player->Set_Type(BULLET_TYPE::SHOTGUN_BULLET);
					break;
				}
				case BULLET_TYPE::GRENADE_BULLET:
				{
					static_cast<CPlayer*>(player)->Set_BulletCount(3);
					player->Set_Type(BULLET_TYPE::GRENADE_BULLET);
					break;
				}
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
void CCollisionMgr::Collide_Bullet_With_Zombie(list<CObj*>_bulletList, list<CObj*>_zombieList)
{
	for (auto& bullet : _bulletList)
	{
		for (auto& zombie : _zombieList)
		{
			if (Check_Sphere(bullet, zombie))
			{
				static_cast<CZombie*>(zombie)->Set_Speed_Zero();
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
				}
			}
		}
	}
}

void CCollisionMgr::Collision_Grenade(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				if (Dst->Get_Type() == 2)
				{
					if (static_cast<CBullet*>(Dst)->Check_Speed() == true) // 추가
					{
						if (Src->Get_HP() <= 1)
						{
							//Dst->Set_Dead();
							Src->Set_Dead();
						}
						else
						{
							//Dst->Set_Dead();
							Src->MinusHP();
						}
					}
				}
				else  // 추가
				{

					if (Src->Get_HP() <= 1)
					{
						Dst->Set_Dead();
						Src->Set_Dead();
					}
					else
					{
						Dst->Set_Dead();
						Src->MinusHP();
					}


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

void CCollisionMgr::Collide_Bullet(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				CComboMgr::Hit();
				if (Dst->Get_Type() == 2)
				{
					if (static_cast<CBullet*>(Dst)->Check_Speed() == true) // 추가
					{
						if (Src->Get_HP() <= 1)
						{
							//Dst->Set_Dead();
							Src->Set_Dead();
						}
						else
						{
							//Dst->Set_Dead();
							Src->MinusHP();
						}
					}
				}
				else  // 추가
				{

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
					}


				}
			}
		}
	}


}

void CCollisionMgr::Collide_Bullet_Player(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				if (Dst->Get_Type() == 2)
				{
					if (static_cast<CBullet*>(Dst)->Check_Speed() == true) // 추가
					{
						Src->Set_Dead();
					}
					else
					{
						//Dst->Set_Dead();
						Src->MinusHP();
					}
				}
			}


		}
	}

}