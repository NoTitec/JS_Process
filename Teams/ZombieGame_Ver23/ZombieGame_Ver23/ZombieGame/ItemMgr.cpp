#include "pch.h"
#include "ItemMgr.h"
#include "CItem.h"
#include "AbstractFactory.h"

OBJ_ITEM_TYPE CItemMgr::m_eSpawnItemType = OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END;
DWORD CItemMgr::m_dwCreateItemTime = GetTickCount();
CObj* CItemMgr::m_pTarget = nullptr;
DWORD CItemMgr::m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END] = { 0, };

void CItemMgr::Initialize()
{
	m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_DRUG] = 20000;
	m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_BARRIER] = 10000;
}

void CItemMgr::Spawn(list<CObj*>* _pItemList, CObj* _pTarget)
{
	if (OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END != m_eSpawnItemType)
	{
		if (m_dwCreateItemTime + m_itemLimitSpawnTimes[m_eSpawnItemType] < GetTickCount())
		{
			int iRandX = rand() % (WINCX - 300);
			int iRandY = rand() % (WINCY - 300);

			_pItemList->push_back(CAbstractFactory<CItem>::Create(iRandX, iRandY, m_eSpawnItemType));
			m_eSpawnItemType = OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END;
		}
	}
	else
	{
		OBJ_ITEM_TYPE iSelectedItemIdx = (OBJ_ITEM_TYPE)(rand() % OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END);
		if (OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != iSelectedItemIdx)
		{
			m_eSpawnItemType = iSelectedItemIdx;
			m_dwCreateItemTime = GetTickCount();
		}
	}

}

void CItemMgr::Spawn_Portal(list<CObj*>* _pItemList)
{
	float iPortalX = WINCX / 2.0f;
	float iPortalY = WINCY / 2.0f - 150.0f;
	_pItemList->push_back(CAbstractFactory<CItem>::Create(iPortalX, iPortalY, OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL));
}
