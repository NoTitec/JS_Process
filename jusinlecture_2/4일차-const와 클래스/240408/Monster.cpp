#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CMonster::CMonster(const char * _pName, int _iAttack, int _iHp)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), _pName);
	m_tInfo.iAttack = _iAttack;
	m_tInfo.iHp = _iHp;
}

CMonster::~CMonster()
{
}

void CMonster::Render()
{
	cout << "-----------------------------------" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
