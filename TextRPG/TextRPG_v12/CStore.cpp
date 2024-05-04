#include "CStore.h"
#include "Character.h"
#include "CInventory.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "Player.h"
CStore::CStore()
{
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize()
{
	ItemBase* weapon= new CWeapon("�ʱް�", 10, 0, 1000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][BEGINNER] = weapon;
	 weapon = new CWeapon("�߱ް�", 20, 0, 2000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][NORMAL] = weapon;
	 weapon = new CWeapon("��ް�", 30, 0, 3000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][RARE] = weapon;
	ItemBase* armor = new CArmor("�ʱް���", 0, 10, 1000);
	armor->Set_Type(IT_ARMOR);
	m_pItem_Array[IT_ARMOR][BEGINNER] = armor;
	 armor = new CArmor("�߱ް���", 0, 20, 2000);
	armor->Set_Type(IT_ARMOR);
	m_pItem_Array[IT_ARMOR][NORMAL] = armor;
	 armor = new CArmor("��ް���", 0, 30, 3000);
	armor->Set_Type(IT_ARMOR);
	m_pItem_Array[IT_ARMOR][RARE] = armor;
}

void CStore::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. �ʱ޻��� 2. �߱޻��� 3. ��޻��� 4. �Ǹ� 5.�� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render_Select_Difficulty_Store(BEGINNER);
			break;
		case 2:
			Render_Select_Difficulty_Store(NORMAL);
			break;

		case 3:
			Render_Select_Difficulty_Store(RARE);
			break;

		case 4:
			Sell_Item();
			break;
		case 5:
			return;
		}

		system("pause");
	}
}

void CStore::Release()
{
	//������ �޸� ����
	for (size_t i = 0; i < IT_END; ++i)
	{
		for (size_t j = 0; j < CLASS_END; ++j)
		{
			SAFE_DELETE(m_pItem_Array[i][j]);
		}
	}
}

void CStore::Render_Select_Difficulty_Store(ITEMCLASS eclass)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		m_pItem_Array[IT_WEAPON][eclass]->Render();
		m_pItem_Array[IT_ARMOR][eclass]->Render();

		cout << "1. ���� ���� 2. �� ���� 3. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Buy_Item(m_pItem_Array[IT_WEAPON][eclass]);
			break;

		case 2:
			Buy_Item(m_pItem_Array[IT_ARMOR][eclass]);
			break;

		case 3:
			return;
		}
	}
}

void CStore::Buy_Item(ItemBase* pItem)
{
	//�÷��̾� �������� ������ ���ݺ��� ���� �κ��丮�� �߰� �õ� ����� �����̸� 
	//���ż��� ����ϰ� ������ ���ҽ�Ű��
	//������ �����ϸ� �ܾ׺������
	if (m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney &&
		m_pInventory->Add_Item(pItem))
	{
		cout << "���� ����" << endl;
		dynamic_cast<Player*>(m_pPlayer)->Minus_Money(pItem->Get_Info().iMoney);
	}
	else
		cout << "�ܾ��� �����մϴ�" << endl;

	system("pause");

}

void CStore::Sell_Item()
{
}
