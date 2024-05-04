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
	ItemBase* weapon= new CWeapon("초급검", 10, 0, 1000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][BEGINNER] = weapon;
	 weapon = new CWeapon("중급검", 20, 0, 2000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][NORMAL] = weapon;
	 weapon = new CWeapon("고급검", 30, 0, 3000);
	weapon->Set_Type(IT_WEAPON);
	m_pItem_Array[IT_WEAPON][RARE] = weapon;
	ItemBase* armor = new CArmor("초급갑옷", 0, 10, 1000);
	armor->Set_Type(IT_ARMOR);
	m_pItem_Array[IT_ARMOR][BEGINNER] = armor;
	 armor = new CArmor("중급갑옷", 0, 20, 2000);
	armor->Set_Type(IT_ARMOR);
	m_pItem_Array[IT_ARMOR][NORMAL] = armor;
	 armor = new CArmor("고급갑옷", 0, 30, 3000);
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
		cout << "1. 초급상점 2. 중급상점 3. 고급상점 4. 판매 5.전 단계 : ";
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
	//아이템 메모리 해제
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

		cout << "1. 무기 구매 2. 방어구 구매 3. 전 단계 : ";
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
	//플레이어 소지금이 아이템 가격보다 높고 인벤토리에 추가 시도 결과가 성공이면 
	//구매성공 출력하고 소지금 감소시키기
	//소지금 부족하면 잔액부족출력
	if (m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney &&
		m_pInventory->Add_Item(pItem))
	{
		cout << "구매 성공" << endl;
		dynamic_cast<Player*>(m_pPlayer)->Minus_Money(pItem->Get_Info().iMoney);
	}
	else
		cout << "잔액이 부족합니다" << endl;

	system("pause");

}

void CStore::Sell_Item()
{
}
