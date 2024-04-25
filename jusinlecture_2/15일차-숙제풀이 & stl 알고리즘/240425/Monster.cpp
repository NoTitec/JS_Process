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
void CMonster::Render()
{
	cout << "-------------몬스터----------------------" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}