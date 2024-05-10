#include "pch.h"
#include "CCollisionMgr.h"
#include "CItem.h"
#include "Player.h"
#include "ItemMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
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
				
				if (OBJ_ITEM_TYPE::GUN == static_cast<CItem*>(item)->Get_Item_Type())
				{
					static_cast<CPlayer*>(player)->Set_GetShotgun();
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
				Dst->Set_Dead();
				Src->Set_Dead();
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
