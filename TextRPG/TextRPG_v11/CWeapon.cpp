#include "CWeapon.h"
CWeapon::CWeapon()
{
}

CWeapon::CWeapon(const char* _pname, int _iattack, int _ihp, int _imoney)
{
	strcpy_s(m_Info.szName,sizeof(m_Info.szName),_pname );
	m_Info.iHp = _ihp;
	m_Info.iAttack = _iattack;
	m_Info.iMoney = _imoney;
}

CWeapon::~CWeapon()
{
}
