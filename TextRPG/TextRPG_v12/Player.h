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
	//돈 설정
	void Add_Money(int _Money) { m_Info.iMoney += _Money; }
	void Minus_Money(int _Money) { m_Info.iMoney -= _Money; }
	//장비장착
	void Equip_Item(ItemBase* pItem);
	//장비해제
	void UnEquip_Item(ItemBase* pItem);
	//장비능력 스탯 적용
	void Apply_Item_Stat(int _iAttack, int _iHp);
	//직업 설정
	void Select_Job();
	//체력설정
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }
public:
	//스탯출력
	virtual void Render() override;
private:
	ItemBase* m_pItemSlot[IT_END];

};

