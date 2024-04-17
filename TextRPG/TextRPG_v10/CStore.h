#pragma once
#include "CPlayer.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void Set_Player(CBase* pPlayer);
	void Initialize();
	void Update();
	void Release();
	void Render_Select_Difficulty_Store(ITEMCLASS eClass);
	void Buy_Item(CBase* pItem);

private:
	CBase* m_pPlayer;
	CBase* m_pItem_Array[IT_END][CLASS_END];
};

