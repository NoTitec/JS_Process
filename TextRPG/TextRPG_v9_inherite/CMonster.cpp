#include "CMonster.h"
#include "stdafx.h"
CMonster::CMonster(const char* _pName, int _iAttack, int iHp)
{
	strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), _pName);
	m_Stat.iAttack = _iAttack;
	m_Stat.iHp = iHp;
}

CMonster::~CMonster()
{
}
