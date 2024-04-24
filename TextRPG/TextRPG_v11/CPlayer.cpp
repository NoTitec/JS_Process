#include "CPlayer.h"
#include "ItemBase.h"
CPlayer::CPlayer() : m_pItem_Weapon(nullptr), m_pItem_Armor(nullptr)
{
}

CPlayer::~CPlayer()
{
	Safe_Delete(m_pItem_Weapon);
	Safe_Delete(m_pItem_Armor);
}

//인벤토리 아이템 추가 max 5
void CPlayer::Add_Item(ItemBase* item)
{
	if(vecInventory.size()<5)
	vecInventory.push_back(item);
}

void CPlayer::SelectJob()
{
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "전사");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case WIZARD:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "마법사");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "도적");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;
	}
}

void CPlayer::Render_Inventory()
{
	for (vector<ItemBase*>::iterator iter = vecInventory.begin();
		iter!=vecInventory.end();
		++iter)
	{
		(*iter)->Render();
	}
}

void CPlayer::Render()
{
	cout << "-------------플레이어----------------------" << endl;
	cout << "이름 : " << m_Info.szName << "\t소지금 : " << m_Info.iMoney << endl;
	cout << "체력 : " << m_Info.iHp << "\t공격력 : " << m_Info.iAttack << endl;
	if (m_pItem_Weapon != nullptr)
		cout << "무기이름 : " << m_pItem_Weapon->Get_Info().szName << "\t아이템공격력:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "방어구이름 : " << m_pItem_Armor->Get_Info().szName << "\t아이템체력:" << m_pItem_Armor->Get_Info().iHp << endl;

}
