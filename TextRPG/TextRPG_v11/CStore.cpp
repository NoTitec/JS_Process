#include "CStore.h"
#include "ItemBase.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "CPlayer.h"
//#include "Define.h"
CStore::CStore()
{
	memset(m_pItem_Array, 0, sizeof(m_pItem_Array));
}

CStore::~CStore()
{
	Release();
}

void CStore::Set_Player(Character* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::Initialize()
{
	m_pItem_Array[IT_WEAPON][BEGINNER] = new CWeapon("초급검", 10, 0, 1000);
	m_pItem_Array[IT_WEAPON][NORMAL] = new CWeapon("중급검", 20, 0, 2000);
	m_pItem_Array[IT_WEAPON][RARE] = new CWeapon("고급검", 30, 0, 3000);

	m_pItem_Array[IT_ARMOR][BEGINNER] = new CArmor("초급옷", 0, 10, 1000);
	m_pItem_Array[IT_ARMOR][NORMAL] = new CArmor("중급옷", 0, 20, 2000);
	m_pItem_Array[IT_ARMOR][RARE] = new CArmor("고급옷", 0, 30, 3000);
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

		for (int j = 0; j < CLASS_END; ++j)
		{
			SAFE_DELETE_MECRO(m_pItem_Array[i][j]);
			//SAFE_DELETE_ARRAY(m_pItem_Array[i][j]);
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
	if (m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney)
	{
		//무기인경우
		if (pItem->Get_Info().iHp == 0)
		{
			//pItem 을 복사하여 new로 새로운 복사본 만들고 복사본의 주소를 
			//void Add_Item(ItemBase* item) 로 플레이어 vecInventory에 넣는 로직
			if (static_cast<CPlayer*>(m_pPlayer)->Get_Inventory_Size() < 5)
			{
				ItemBase* temp = new CWeapon(pItem->Get_Info().szName, pItem->Get_Info().iAttack, pItem->Get_Info().iHp, pItem->Get_Info().iMoney);
				static_cast<CPlayer*>(m_pPlayer)->Add_Item(temp);
				static_cast<CPlayer*>(m_pPlayer)->Set_Money(m_pPlayer->Get_Info().iMoney - pItem->Get_Info().iMoney);
				cout << "무기구매 성공" << endl;
			}
			else
			{
				cout << "인벤토리 가득참" << endl;
			}
		}
		else
		{
			if (static_cast<CPlayer*>(m_pPlayer)->Get_Inventory_Size() < 5)
			{
				ItemBase* temp = new CArmor(pItem->Get_Info().szName, pItem->Get_Info().iAttack, pItem->Get_Info().iHp, pItem->Get_Info().iMoney);
				static_cast<CPlayer*>(m_pPlayer)->Add_Item(temp);
				static_cast<CPlayer*>(m_pPlayer)->Set_Money(m_pPlayer->Get_Info().iMoney - pItem->Get_Info().iMoney);
				cout << "방어구구매 성공" << endl;
			}
			else
			{
				cout << "인벤토리 가득참" << endl;
			}
		}
		system("pause");
	}
	else
	{
		cout << "잔액이 부족합니다" << endl;
		system("pause");
	}
}
