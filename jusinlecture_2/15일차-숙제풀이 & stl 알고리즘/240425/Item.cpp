#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}

CItem::CItem(const char * _pName, int _iAttack, int _iHp, int _iMoney)
	: CObj(_pName, _iAttack, _iHp, _iMoney), m_eType(IT_END), m_eState(ST_UNEQUIP)
{
}

CItem::CItem(const CItem & rhs)
	: CObj(rhs), m_eType(rhs.m_eType), m_eState(ST_UNEQUIP)
{
}


CItem::~CItem()
{
}

void CItem::Render()
{
	cout << "-------------������----------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << "\t���� : " << m_tInfo.iMoney << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}
