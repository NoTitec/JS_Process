#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(const char* _szname, int _iattack, int _ihp)
	: CBase(_szname,_iattack,_ihp)
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
