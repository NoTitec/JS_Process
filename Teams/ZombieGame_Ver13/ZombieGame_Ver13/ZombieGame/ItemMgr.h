#pragma once

#include "Obj.h"
class CObj;
class CItemMgr
{
public:
	static void Initialize();
	static void Spawn(list<CObj*>* _pItemList, CObj* _pTarget, int _iMaxNumberInMap);
public:
	static void Set_Create_Item_Time(DWORD _dwCreateItemTime) { m_dwCreateItemTime = _dwCreateItemTime; }

private:
	static DWORD m_dwCreateItemTime;
	static CObj* m_pTarget;
	static DWORD m_itemSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END];
	static DWORD m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END];
};

