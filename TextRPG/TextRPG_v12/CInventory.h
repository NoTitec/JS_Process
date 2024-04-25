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
	//������ �Ǹ�
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
	//�÷��̾� ����Ʈ
	Character* m_pPlayer;
	//�κ��丮 ���� ������
	vector<ItemBase*>	m_vecInven;
	const	size_t	m_iSize;
};

