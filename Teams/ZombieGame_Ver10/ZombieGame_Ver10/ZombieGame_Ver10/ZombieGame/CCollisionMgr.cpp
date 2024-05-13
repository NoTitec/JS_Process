#include "pch.h"
#include "CCollisionMgr.h"
#include "Turret.h"
#include "CItem.h"
#include "Player.h"
#include "ItemMgr.h"
#include "CKeyMgr.h"
#include "CZombieMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{

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

void CCollisionMgr::Collide_Item(list<CObj*> _itemList, list<CObj*> _playerList)
{
	for (auto& item : _itemList)
	{
		for (auto& player : _playerList)
		{
			if (Check_Sphere(item, player))
			{
				item->Set_Dead();
				CItemMgr::m_dwCreateItemTime = GetTickCount();
				/*switch (static_cast<CItem*>(item)->Get_Item_Type())
				{
				case OBJ_ITEM_TYPE::GUN:
				{
					static_cast<CPlayer*>(player)->Set_GetShotgun();
					break;
				}
				}*/
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

bool CCollisionMgr::Check_Sphere(CObj* _Dst, CObj* _Src)
{
	float fDiffY = _Dst->Get_Info().fY - _Src->Get_Info().fY;
	float fDiffX = _Dst->Get_Info().fX - _Src->Get_Info().fX;
	
	float fR = std::sqrtf((fDiffY * fDiffY) + (fDiffX * fDiffX));
	float fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	return fRadius >= fR;
}
