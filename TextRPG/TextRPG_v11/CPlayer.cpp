#include "CPlayer.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "ItemBase.h"
//RTTI header�߰�
#include <typeinfo>
CPlayer::CPlayer() : m_pItem_Weapon(nullptr), m_pItem_Armor(nullptr)
{
}

CPlayer::~CPlayer()
{
	for (ItemBase* ptr : vecInventory)
	{
		delete ptr;
	}
	vecInventory.clear();
	vector<ItemBase*>().swap(vecInventory);
	//�÷��̾� �Ҹ��ڼ� Safedelete�ϸ� Maingame���� �÷��̾� �����Ҷ� ���� �߻� ��?
	//Safe_Delete(m_pItem_Weapon);
	//Safe_Delete(m_pItem_Armor);
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
		m_Info.iAttack = 20;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "����");
		m_Info.iAttack = 50;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;
	}
}

void CPlayer::Start_Inventory()
{
	while (true)
	{
		system("cls");
		Render_Inventory();
		
		cout << "1.������ ���� 2.���� ���� 3. �� ���� 4.������" << endl;
		int iInput(0);
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			//���ϴ� ��� �̸� �Է�
			cout << "������ ������ �̸� �Է� : " << endl;
			char szTemp[32];
			cin >> szTemp;
			if (!vecInventory.empty())
			{
				for (vector<ItemBase*>::iterator Itemiter = vecInventory.begin(); Itemiter != vecInventory.end(); ++Itemiter)
				{
					if (0 == strcmp(szTemp, (*Itemiter)->Get_Info().szName))
					{
						//Itemiter �� ��ü�� CWeapon���� CArmor���� ��� Ȯ���ϴ°�?
						//RTTI �׽�Ʈ
						if (typeid(**Itemiter) == typeid(CWeapon))
						{
							Set_Weapon(*Itemiter);
							cout << "��������";
							system("pause");
						}
						else
						{
							Set_Armor(*Itemiter);
							cout << "������";
							system("pause");
						}
						break;
					}
				}
			}
			break;
		case 2:
			if (m_pItem_Weapon != nullptr)
			{
				Set_Weapon();
				cout << "��������" << endl;
				system("pause");
			}
			break;
		case 3:
			if (m_pItem_Armor != nullptr)
			{
				Set_Armor();
				cout << "������" << endl;
				system("pause");
			}
			break;
		case 4:
			return;
		}
	}
}

void CPlayer::Render_Inventory()
{
	cout << "-------�κ��丮-------" << endl;
	for (vector<ItemBase*>::iterator iter = vecInventory.begin();
		iter!=vecInventory.end();
		++iter)
	{
		(*iter)->Render();
	}
	cout << "------------------------" << endl;
}

void CPlayer::Render()
{
	cout << "-------------�÷��̾�----------------------" << endl;
	cout << "�̸� : " << m_Info.szName << "\t������ : " << m_Info.iMoney << endl;
	cout << "ü�� : " << m_Info.iHp << "\t���ݷ� : " << m_Info.iAttack << endl;
	if (m_pItem_Weapon != nullptr)
		cout << "�����̸� : " << m_pItem_Weapon->Get_Info().szName << "\t������ݷ�:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "���̸� : " << m_pItem_Armor->Get_Info().szName << "\t������:" << m_pItem_Armor->Get_Info().iHp << endl;
	cout << "----------------------------------------------" << endl;
}
