#include "Player.h"

Player::Player()
{
	//Ư�� �ڷ����ƴϸ� memset ���� �б�
	memset(m_pItemSlot, 0, sizeof(m_pItemSlot));
}

Player::~Player()
{
}

void Player::Equip_Item(ItemBase* pItem)
{
	ITEMTYPE eType = pItem->Get_Type();

	// ���� �������� �����Ǿ� �ִ� ����
	if (m_pItemSlot[eType])
	{
		Apply_Item_Stat(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		m_pItemSlot[eType]->Set_State(ST_UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}

	Apply_Item_Stat(pItem->Get_Info().iAttack, pItem->Get_Info().iHp);
	dynamic_cast<ItemBase*>(pItem)->Set_State(ST_EQUIP);
	m_pItemSlot[eType] = pItem;
}

void Player::UnEquip_Item(ItemBase* pItem)
{
	ITEMTYPE eType = pItem->Get_Type();

	if (nullptr != m_pItemSlot[eType])
	{
		Apply_Item_Stat(-m_pItemSlot[eType]->Get_Info().iAttack, -m_pItemSlot[eType]->Get_Info().iHp);
		m_pItemSlot[eType]->Set_State(ST_UNEQUIP);
		m_pItemSlot[eType] = nullptr;
	}
}

void Player::Apply_Item_Stat(int _iAttack, int _iHp)
{
	m_Info.iAttack += _iAttack;
	m_Info.iHp += _iHp;
}

void Player::Select_Job()
{
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "����");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case WIZARD:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "������");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "����");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;
	}
}

void Player::Render()
{
	cout << "--------Player----------";
	cout << "Job : " << m_Info.szName << endl;
	cout << "Attack : " << m_Info.iAttack << endl;
	cout << "Hp : " << m_Info.iHp << endl;
	cout << "Money : " << m_Info.iMoney << endl;
	cout << "--------------------------" << endl;
}
