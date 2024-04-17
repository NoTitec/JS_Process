#include "CPlayer.h"
#include "CItem.h"
CPlayer::CPlayer() : m_pItem_Weapon(nullptr),m_pItem_Armor(nullptr)
{
}

CPlayer::~CPlayer()
{
	SAFE_DELETE(m_pItem_Armor);
	SAFE_DELETE(m_pItem_Weapon);
}

void CPlayer::Set_Weapon(CBase* weapon)
{
	CBase* temp = new CItem(weapon->Get_Info().szName,weapon->Get_Info().iAttack,weapon->Get_Info().iHp);
	m_pItem_Weapon = temp;
}

void CPlayer::SelectJob()
{
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "도적");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;
	}
}

void CPlayer::Render()
{
	cout << "-------------플레이어----------------------" << endl;
	cout << "이름 : " << m_tInfo.szName << "\t소지금 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
	if(m_pItem_Weapon!=nullptr)
	cout << "아이템이름" << m_pItem_Weapon->Get_Info().szName << "\t아이템공격력:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "아이템이름" << m_pItem_Armor->Get_Info().szName << "\t아이템체력:" << m_pItem_Armor->Get_Info().iHp << endl;

}
