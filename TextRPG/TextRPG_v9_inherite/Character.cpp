#include "Character.h"
#include "stdafx.h"
Character::~Character()
{

}

void Character::Take_Damage(int iAttack)
{
	m_Stat.iHp -= iAttack;
}

int Character::Get_Attack()
{
	return m_Stat.iAttack;
}

int Character::Get_Hp()
{
	return m_Stat.iHp;
}

void Character::Set_Hp(int iHp)
{
	m_Stat.iHp = iHp;
}

void Character::Render() const
{
	cout << "-----------------------------------" << endl;
	cout << "�̸� : " << m_Stat.szName << endl;
	cout << "ü�� : " << m_Stat.iHp << "\t���ݷ� : " << m_Stat.iAttack << endl;
}
