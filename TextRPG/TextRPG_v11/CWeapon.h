#pragma once
#include "ItemBase.h"
class CWeapon final: public ItemBase
{
public:
    CWeapon();
    CWeapon(const char* _pname, int _iattack, int _ihp, int _imoney);
    virtual ~CWeapon();
public:
    virtual void Render() { 
        cout << "----무기정보----" << endl;
        cout << m_Info.szName << endl;
        cout << m_Info.iAttack << endl;
        cout << m_Info.iHp << endl;
        //cout << m_Info.iMoney << endl;
    };

};

