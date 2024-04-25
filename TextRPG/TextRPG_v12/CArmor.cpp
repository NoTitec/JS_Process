#include "CArmor.h"

CArmor::CArmor()
{
}

CArmor::CArmor(const CArmor& rhs)
    :ItemBase(rhs), e_type(rhs.e_type), e_state(ST_UNEQUIP)
{
}

CArmor::CArmor(const char* _pname, int _iattack, int _ihp, int _imoney)
    :ItemBase(_pname, _iattack, _ihp, _imoney), e_type(IT_END), e_state(ST_UNEQUIP)
{
}

CArmor::~CArmor()
{
}

void CArmor::Render()
{
    cout << "-------------������----------------------" << endl;
    cout << "�̸� : " << m_Info.szName << "\t���� : " << m_Info.iMoney << endl;
    cout << "ü�� : " << m_Info.iHp << "\t���ݷ� : " << m_Info.iAttack << endl;
}

ITEMTYPE CArmor::Get_Type()
{
    return e_type;
}

void CArmor::Set_Type(ITEMTYPE eType)
{
    e_type = eType;
}

EQUIPSTATE CArmor::Get_State()
{
    return e_state;
}

void CArmor::Set_State(EQUIPSTATE eTate)
{
    e_state = eTate;
}
