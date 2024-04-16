#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}

CItem::CItem(const char * _pName, int _iAttack, int _iHp, int _iMoney)
	: CObj(_pName, _iAttack, _iHp, _iMoney)
{
}


CItem::~CItem()
{
}

void CItem::Render()
{
	cout << "-------------아이템----------------------" << endl;
	cout << "이름 : " << m_tInfo.szName << "\t가격 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
