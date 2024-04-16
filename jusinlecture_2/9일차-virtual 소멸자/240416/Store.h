#pragma once

#include "Player.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

public:
	void		Initialize();
	void		Update();
	void		Render(ITEMCLASS eClass);
	void		Release();

	void		Buy_Item(CObj* pItem);

private:
	CObj*		m_pPlayer;

	CObj*		m_pItem[IT_END][CLASS_END];

};

