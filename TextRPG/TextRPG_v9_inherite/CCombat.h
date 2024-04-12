#pragma once
#include "CPlayer.h"
#include "CMonster.h"

class Character;

class CCombat
{
public:
	CCombat();
	~CCombat();
public:
	static int Battle(Character* player, Character* monster);
};

