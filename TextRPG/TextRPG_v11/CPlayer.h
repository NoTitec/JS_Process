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
	//체력설정
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }
	//소지금액 설정
	void Set_Money(int _imoney) {
		m_Info.iMoney = _imoney;
	}
	//무기 해제
	void Set_Weapon() { m_pItem_Weapon = nullptr; };
	//무기 설정
	void Set_Weapon(ItemBase* weapon) { m_pItem_Weapon = weapon; };
	//방어구 해제
	void Set_Armor() { m_pItem_Armor = nullptr; };
	//방어구 설정
	void Set_Armor(ItemBase* armor) { m_pItem_Armor = armor; }
	//아이템 인벤토리 추가함수 max 5
	void Add_Item(ItemBase* item);
	//직업선택
	void SelectJob();
	//인벤토리 진입
	void Start_Inventory();
	//플레이어 인벤토리 출력
	void Render_Inventory();
	size_t Get_Inventory_Size() {
		return vecInventory.size();
	}
public:
	virtual void Render();
private:
	//인벤토리 벡터
	vector<ItemBase*> vecInventory;

	//장착 아이템 포인터
	ItemBase* m_pItem_Weapon;
	ItemBase* m_pItem_Armor;
};

