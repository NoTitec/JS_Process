#include "CItem.h"

CItem::CItem()
{
}
CItem::CItem(const char* _itemname, int _iattack, int _ihp)
	: CBase(_itemname, _iattack, _ihp)
{
	
}
CItem::CItem(const char* _itemname, int _iattack, int _ihp, int _imoney)
	: CBase(_itemname,_iattack,_ihp,_imoney)
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
