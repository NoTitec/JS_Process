#include "pch.h"
#include "ItemMgr.h"
#include "CItem.h"
#include "AbstractFactory.h"

DWORD CItemMgr::m_dwCreateItemTime = GetTickCount();
CObj* CItemMgr::m_pTarget = nullptr;

DWORD CItemMgr::m_itemSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END] = { 0, };
DWORD CItemMgr::m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END] = { 0, };

void CItemMgr::Initialize()
{
	for (int i = 0; i < OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END; ++i)
	{
		m_itemSpawnTimes[i] = GetTickCount();
	}

	m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_DRUG] = 20000;
	m_itemLimitSpawnTimes[OBJ_ITEM_TYPE::OBJ_ITEM_BARRIER] = 10000;
}

void CItemMgr::Spawn(list<CObj*>* _pItemList, CObj* _pTarget, int _iMaxNumberInMap)
{
	int iRandX = rand() % (WINCX - 250);
	int iRandY = rand() % (WINCY - 250);

	bool bValidNumber = _iMaxNumberInMap > _pItemList->size();

	if (bValidNumber)
	{
		int iSelectedItemIdx = rand() % OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END;
		
		if (OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != iSelectedItemIdx)
		{
			if (m_itemSpawnTimes[iSelectedItemIdx] + m_itemLimitSpawnTimes[iSelectedItemIdx] < GetTickCount())
			{
				OBJ_ITEM_TYPE eItemType = (OBJ_ITEM_TYPE)(iSelectedItemIdx);
				_pItemList->push_back(CAbstractFactory<CItem>::Create(iRandX, iRandY, eItemType));
				static_cast<CItem*>(_pItemList->back())->Set_Target(_pTarget);
				m_itemSpawnTimes[iSelectedItemIdx] = GetTickCount();
			}
		}
	}
}

void CItemMgr::Spawn_Portal(list<CObj*>* _pItemList)
{
	float iPortalX = WINCX / 2.0f;
	float iPortalY = WINCY / 2.0f - 150.0f;

	_pItemList->push_back(CAbstractFactory<CItem>::Create(iPortalX, iPortalY, OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL));
}
