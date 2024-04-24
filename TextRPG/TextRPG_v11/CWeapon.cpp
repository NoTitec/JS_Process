#include "CWeapon.h"
#include "Define.h"
CWeapon::CWeapon()
{
	memset(&m_Info, 0, sizeof(INFO));
}

CWeapon::CWeapon(const char* _pname, int _iattack, int _ihp, int _imoney) : ItemBase(_pname, _iattack, _ihp, _imoney)
{
}

CWeapon::~CWeapon()
{
}
