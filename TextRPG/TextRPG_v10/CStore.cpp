#include "CStore.h"
#include "CItem.h"
CStore::CStore() :m_pPlayer(nullptr)
{
	memset(m_pItem_Array, 0, sizeof(m_pItem_Array));
}

CStore::~CStore()
{
	Release();
}

void CStore::Set_Player(CBase* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::Initialize()
{
	m_pItem_Array[IT_WEAPON][BEGINNER] = new CItem("초급검", 10, 0, 1000);
	m_pItem_Array[IT_WEAPON][NORMAL] = new CItem("중급검", 20, 0, 2000);
	m_pItem_Array[IT_WEAPON][RARE] = new CItem("고급검", 30, 0, 3000);

	m_pItem_Array[IT_ARMOR][BEGINNER] = new CItem("초급옷", 0, 10, 1000);
	m_pItem_Array[IT_ARMOR][NORMAL] = new CItem("중급옷", 0, 20, 2000);
	m_pItem_Array[IT_ARMOR][RARE] = new CItem("고급옷", 0, 30, 3000);

}

void CStore::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 초급상점 2. 중급상점 3. 고급상점 4. 전 단계 : ";
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
			return;

		}

		system("pause");
	}
}

void CStore::Release()
{
	for (int i = 0; i < IT_END; ++i)
	{
		for (int j = 0; j < CLASS_END; ++i)
		{
			SAFE_DELETE(m_pItem_Array[i][j]);
		}
	}
}

void CStore::Render_Select_Difficulty_Store(ITEMCLASS eClass)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		m_pItem_Array[IT_WEAPON][eClass]->Render();
		m_pItem_Array[IT_ARMOR][eClass]->Render();

		cout << "1. 무기 구매 2. 방어구 구매 3. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Buy_Item(m_pItem_Array[IT_WEAPON][eClass]);
			break;

		case 2:
			Buy_Item(m_pItem_Array[IT_ARMOR][eClass]);
			break;

		case 3:
			return;
		}
	}
}

void CStore::Buy_Item(CBase* pItem)
{
	if (m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney)
	{
		//무기인경우
		if (pItem->Get_Info().iHp == 0)
		{
			static_cast<CPlayer*>(m_pPlayer)->Set_Weapon(pItem);
		}
		else
		{
			static_cast<CPlayer*>(m_pPlayer)->Set_Armor(pItem);
		}
		cout << "구매 성공" << endl;
	}
	else
		cout << "잔액이 부족합니다" << endl;

	system("pause");
}
