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
	cout << "-------------����----------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;

}
