#pragma once
#include "Character.h"
#include "ItemBase.h"

class CInventory
{
public:
	CInventory();
	~CInventory();

public:
	void		Set_Player(Character* pPlayer) { m_pPlayer = pPlayer; }
	bool		Add_Item(ItemBase* pItem);
	//아이템 판매
	bool		Sell_Item(int iIndex, int* pMoney);

public:
	void		Initialize();
	void		Update();
	void		Render();
	void		Release();

private:
	void		Equip_Item();
	void		Unequip_Item();

private:
	//플레이어 포인트
	Character* m_pPlayer;
	//인벤토리 벡터 포인터
	vector<ItemBase*>	m_vecInven;
	const	size_t	m_iSize;
};

