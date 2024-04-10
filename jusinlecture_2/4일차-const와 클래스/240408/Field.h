#pragma once

#include "Player.h"
#include "Monster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void		Set_Player(CPlayer* pPlayer) { m_pCopyPlayer = pPlayer; }
	int			Fight();

public:
	void		Initialize();
	void		Update();
	void		Release();

private:
	CPlayer*	m_pCopyPlayer;
	CMonster*	m_pMonster;
};

