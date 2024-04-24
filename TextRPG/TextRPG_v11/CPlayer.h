#pragma once
#include "stdafx.h"
#include "Character.h"
#include "ItemBase.h"
#include <vector>
class CPlayer final: public Character
{
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }
	void Set_Weapon(ItemBase* weapon) { m_pItem_Weapon = weapon; };
	void Set_Armor(ItemBase* armor) { m_pItem_Armor = armor; }
	//아이템 인벤토리 추가함수 max 5
	void Add_Item(ItemBase* item);
	void SelectJob();
	void Render_Inventory();
public:
	virtual void Render();
private:
	//인벤토리 벡터
	vector<ItemBase*> vecInventory;
	//장착 아이템 포인터
	ItemBase* m_pItem_Weapon;
	ItemBase* m_pItem_Armor;
};

