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
	cout << "-------------����----------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}