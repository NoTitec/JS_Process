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

//�κ��丮 ������ �߰� max 5
void CPlayer::Add_Item(ItemBase* item)
{
	if(vecInventory.size()<5)
	vecInventory.push_back(item);
}

void CPlayer::SelectJob()
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
	cout << "-------------�÷��̾�----------------------" << endl;
	cout << "�̸� : " << m_Info.szName << "\t������ : " << m_Info.iMoney << endl;
	cout << "ü�� : " << m_Info.iHp << "\t���ݷ� : " << m_Info.iAttack << endl;
	if (m_pItem_Weapon != nullptr)
		cout << "�����̸� : " << m_pItem_Weapon->Get_Info().szName << "\t�����۰��ݷ�:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "���̸� : " << m_pItem_Armor->Get_Info().szName << "\t������ü��:" << m_pItem_Armor->Get_Info().iHp << endl;

}
