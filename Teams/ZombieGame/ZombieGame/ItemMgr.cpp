#include "pch.h"
#include "ItemMgr.h"
#include "CItem.h"
#include "AbstractFactory.h"

DWORD CItemMgr::m_dwCreateItemTime = GetTickCount();
void CItemMgr::Create_Item(list<CObj*>* _pItemList)
{
	int iRandX = rand() % (WINCX - 100);
	int iRandY = rand() % (WINCY - 100);
	OBJ_ITEM_TYPE eItemType = static_cast<OBJ_ITEM_TYPE>(rand() % OBJ_ITEM_TYPE::OBJ_ITEM_TYPE_END);

	if (m_dwCreateItemTime + 5000 < GetTickCount() && _pItemList->size() < 1)
	{
		_pItemList->push_back(CAbstractFactory<CItem>::Create());
		_pItemList->back()->Set_Pos(iRandX, iRandY);
		static_cast<CItem*>(_pItemList->back())->Set_Item_Type(eItemType);
	}
}