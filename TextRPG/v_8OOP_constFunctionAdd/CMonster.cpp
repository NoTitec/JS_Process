#include "CMonster.h"
#include "stdafx.h"
//�⺻ ������ �̴ϼȶ����� �ۼ���

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
	cout << "�̸� : " << m_tInfo.saName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}
