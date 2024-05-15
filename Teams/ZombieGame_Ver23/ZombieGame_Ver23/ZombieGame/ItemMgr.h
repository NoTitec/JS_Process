#pragma once

#include "Obj.h"
class CObj;
class CItemMgr
{
public:
	static void Initialize();
	static void Spawn(list<CObj*>* _pItemList, CObj* _pTarget);
	static void Spawn_Portal(list<CObj*>* _pItemList);

private:
	static OBJ_ITEM_TYPE m_eSpawnItemType;
	static DWORD m_dwCreateItemTime;

	static CObj* m_pTarget;
	static DWORD m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END];
};

