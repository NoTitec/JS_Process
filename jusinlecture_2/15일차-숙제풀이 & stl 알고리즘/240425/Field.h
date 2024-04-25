#pragma once

#include "Player.h"
#include "Monster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void		Set_Player(CObj* pPlayer) { m_pCopyPlayer = pPlayer; }
	int			Fight();

public:
	void		Initialize();
	void		Update();
	void		Release();

private:
	CObj*	m_pCopyPlayer;
	CObj*	m_pMonster;
};

