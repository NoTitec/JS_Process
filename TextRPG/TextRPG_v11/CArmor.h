#pragma once
#include "ItemBase.h"
class CArmor : public ItemBase
{
public:
    CArmor();
    CArmor(const char* _pname, int _iattack, int _ihp, int _imoney);
    virtual ~CArmor();
public:
    virtual void Render() {
        cout << "----방어구정보----" << endl;
        cout << "이름 : ";
        cout << m_Info.szName << endl;
        //cout << "공격력 : ";
        //cout << m_Info.iAttack << endl;
        cout << "방어력 : ";
        cout << m_Info.iHp << endl;
        cout << "가격 : ";
        cout << m_Info.iMoney << endl;
    };
};

