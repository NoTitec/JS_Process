#pragma once
#include "ItemBase.h"
class Character;
class CInventory;

class CStore
{
public:
	CStore();
	~CStore();

	void Initialize();
	void Update();
	void Release();
public:
	void Set_Player(Character* pPlayer) { m_pPlayer = pPlayer; }
	void Set_Inventory(CInventory* pInven) { m_pInventory = pInven; }
	void Render_Select_Difficulty_Store(ITEMCLASS eclass);
	//인벤토리에 상점 아이템 복사본 넣는함수
	void Buy_Item(ItemBase* pItem);
	void Sell_Item();
private:
	Character* m_pPlayer;
	CInventory* m_pInventory;
	ItemBase* m_pItem_Array[IT_END][CLASS_END];
};

