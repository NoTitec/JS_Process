#include "CMonster.h"
#include "stdafx.h"
//기본 생성자 이니셜라이즈 작성됨

CMonster::CMonster(const char* _pName, int _iAttack, int _iHp)
{
	strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), _pName);
	m_tInfo.iAttack = _iAttack;
	m_tInfo.iHp = _iHp;
}

CMonster::~CMonster()
{
}

void CMonster::Take_Damage(int iAttack)
{
	m_tInfo.iHp -= iAttack;
}

void CMonster::Render() const
{
	cout << "-----------------------------------" << endl;
	cout << "이름 : " << m_tInfo.saName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
