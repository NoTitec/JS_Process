#pragma once
#include "ItemBase.h"
#include "Character.h"
class CStore
{
public:
	CStore();
	~CStore();

public:
	void Set_Player(Character* pPlayer);
	void Initialize();
	void Update();
	void Release();
	void Render_Select_Difficulty_Store(ITEMCLASS eclass);
	void Buy_Item(ItemBase* pItem);

private:
	Character* m_pPlayer;
	ItemBase* m_pItem_Array[IT_END][CLASS_END];
};

