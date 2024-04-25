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
	CObj*			m_pPlayer;
	//인벤토리 벡터 포인터
	vector<CObj*>	m_vecInven;
	const	size_t	m_iSize;
};

