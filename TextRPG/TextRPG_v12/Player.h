#pragma once
#include "Character.h"
#include "ItemBase.h"

class Player final:public Character
{
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF, END };
public:
	Player();
	virtual ~Player();

public:
	//�� ����
	void Add_Money(int _Money) { m_Info.iMoney += _Money; }
	void Minus_Money(int _Money) { m_Info.iMoney -= _Money; }
	//�������
	void Equip_Item(ItemBase* pItem);
	//�������
	void UnEquip_Item(ItemBase* pItem);
	//���ɷ� ���� ����
	void Apply_Item_Stat(int _iAttack, int _iHp);
	//���� ����
	void Select_Job();
	//ü�¼���
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }
public:
	//�������
	virtual void Render() override;
private:
	ItemBase* m_pItemSlot[IT_END];

};

