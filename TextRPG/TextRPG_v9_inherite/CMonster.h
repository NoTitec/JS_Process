#pragma once
#include "Character.h"
class CMonster : public Character
{
public:
	enum Difficulty
	{
		EASY = 1,
		NORMAL,
		HARD
	};

public:
	CMonster(const char* _pName, int _iAttack, int iHp);
	~CMonster();
};

