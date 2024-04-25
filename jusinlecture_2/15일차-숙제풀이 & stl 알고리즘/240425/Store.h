#pragma once

#include "Player.h"
#include "Inven.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	void		Set_Inven(CInven* pInven) { m_pInven = pInven; }

public:
	void		Initialize();
	void		Update();
	void		Render(ITEMCLASS eClass);
	void		Release();

	void		Buy_Item(CObj* pItem);
	void		Sell_Item();
	

private:
	CObj*		m_pPlayer;
	CInven*		m_pInven;

	CObj*		m_pItem[IT_END][CLASS_END];

};

