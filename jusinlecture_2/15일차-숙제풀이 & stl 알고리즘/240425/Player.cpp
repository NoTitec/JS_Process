#include "stdafx.h"
#include "Player.h"
#include "Item.h"


CPlayer::CPlayer()
{
	memset(m_pItemSlot, 0, sizeof(m_pItemSlot));
}

CPlayer::~CPlayer()
{
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
		m_tInfo.iHp		= 100;
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

void CPlayer::Equip_Item(CObj * pItem)
{
	ITEMTYPE eType = dynamic_cast<CItem*>(pItem)->Get_Type();

	// 기존 아이템이 장착되어 있는 상태
	if (m_pItemSlot[eType])
	{
		Item_Ability(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItemSlot[eType])->Set_State(ST_UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}
	
	Item_Ability(pItem->Get_Info().iAttack, pItem->Get_Info().iHp);
	dynamic_cast<CItem*>(pItem)->Set_State(ST_EQUIP);
	m_pItemSlot[eType] = pItem;
}

void CPlayer::Unequip_Item(CObj * pItem)
{
	ITEMTYPE eType = dynamic_cast<CItem*>(pItem)->Get_Type();

	if (nullptr != m_pItemSlot[eType])
	{
		Item_Ability(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItemSlot[eType])->Set_State(ST_UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}

}

void CPlayer::Item_Ability(int _iAttack, int _iHp)
{
	m_tInfo.iAttack += _iAttack;
	m_tInfo.iHp += _iHp;
}

void CPlayer::Render()
{
	cout << "-------------플레이어----------------------" << endl;
	cout << "이름 : " << m_tInfo.szName << "\t소지금 : " << m_tInfo.iMoney << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
