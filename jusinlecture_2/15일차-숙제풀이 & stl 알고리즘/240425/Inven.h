#pragma once

#include "Player.h"

class CInven
{
public:
	CInven();
	~CInven();

public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	bool		Buy_Item(CObj* pItem);
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
	CObj*			m_pPlayer;
	//�κ��丮 ���� ������
	vector<CObj*>	m_vecInven;
	const	size_t	m_iSize;
};

