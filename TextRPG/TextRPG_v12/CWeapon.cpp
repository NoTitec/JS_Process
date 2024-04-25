#include "CWeapon.h"

CWeapon::CWeapon()
{
}

CWeapon::CWeapon(const CWeapon& rhs)
    :ItemBase(rhs),e_type(rhs.e_type),e_state(ST_UNEQUIP)
{
}

CWeapon::CWeapon(const char* _pname, int _iattack, int _ihp, int _imoney)
    :ItemBase(_pname,_iattack,_ihp,_imoney),e_type(IT_END),e_state(ST_UNEQUIP)
{
}

CWeapon::~CWeapon()
{
}

void CWeapon::Render()
{
    cout << "-------------������----------------------" << endl;
    cout << "�̸� : " << m_Info.szName << "\t���� : " << m_Info.iMoney << endl;
    cout << "ü�� : " << m_Info.iHp << "\t���ݷ� : " << m_Info.iAttack << endl;
}

ITEMTYPE CWeapon::Get_Type()
{
    return e_type;
}

void CWeapon::Set_Type(ITEMTYPE eType)
{
    e_type = eType;
}

EQUIPSTATE CWeapon::Get_State()
{
    return e_state;
}

void CWeapon::Set_State(EQUIPSTATE eTate)
{
    e_state = eTate;
}
