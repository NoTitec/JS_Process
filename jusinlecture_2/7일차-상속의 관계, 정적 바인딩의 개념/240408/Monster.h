#pragma once

#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(const char* _pName, int _iAttack, int _iHp);
	~CMonster();
};

