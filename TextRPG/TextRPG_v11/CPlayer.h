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
	//������ �κ��丮 �߰��Լ� max 5
	void Add_Item(ItemBase* item);
	void SelectJob();
	void Render_Inventory();
public:
	virtual void Render();
private:
	//�κ��丮 ����
	vector<ItemBase*> vecInventory;
	//���� ������ ������
	ItemBase* m_pItem_Weapon;
	ItemBase* m_pItem_Armor;
};

