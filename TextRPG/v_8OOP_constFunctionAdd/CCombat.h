#pragma once
#include "CPlayer.h"
#include "CMonster.h"

class CCombat
{
public:
	CCombat();
	~CCombat();
public:
	static int Battle(CPlayer* player, CMonster* monster);
};

