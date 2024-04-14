#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}

CMonster::CMonster(const char * _pName, int _iAttack, int _iHp)
	: CObj(_pName, _iAttack, _iHp)
{
	
}

CMonster::~CMonster()
{
}
