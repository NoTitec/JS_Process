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
	//ü�¼���
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }
	//�����ݾ� ����
	void Set_Money(int _imoney) {
		m_Info.iMoney = _imoney;
	}
	//���� ����
	void Set_Weapon() { m_pItem_Weapon = nullptr; };
	//���� ����
	void Set_Weapon(ItemBase* weapon) { m_pItem_Weapon = weapon; };
	//�� ����
	void Set_Armor() { m_pItem_Armor = nullptr; };
	//�� ����
	void Set_Armor(ItemBase* armor) { m_pItem_Armor = armor; }
	//������ �κ��丮 �߰��Լ� max 5
	void Add_Item(ItemBase* item);
	//��������
	void SelectJob();
	//�κ��丮 ����
	void Start_Inventory();
	//�÷��̾� �κ��丮 ���
	void Render_Inventory();
	size_t Get_Inventory_Size() {
		return vecInventory.size();
	}
public:
	virtual void Render();
private:
	//�κ��丮 ����
	vector<ItemBase*> vecInventory;

	//���� ������ ������
	ItemBase* m_pItem_Weapon;
	ItemBase* m_pItem_Armor;
};

