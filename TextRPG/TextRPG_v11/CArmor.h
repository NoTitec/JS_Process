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
        cout << "----������----" << endl;
        cout << "�̸� : ";
        cout << m_Info.szName << endl;
        //cout << "���ݷ� : ";
        //cout << m_Info.iAttack << endl;
        cout << "���� : ";
        cout << m_Info.iHp << endl;
        cout << "���� : ";
        cout << m_Info.iMoney << endl;
    };
};

