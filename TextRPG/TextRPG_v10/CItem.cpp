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
	cout << "-------------������----------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << "\t���� : " << m_tInfo.iMoney << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;

}
