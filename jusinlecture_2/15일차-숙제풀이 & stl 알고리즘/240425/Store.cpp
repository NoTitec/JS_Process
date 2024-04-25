#include "stdafx.h"
#include "Store.h"
#include "Item.h"


CStore::CStore() : m_pPlayer(nullptr)
{
	memset(m_pItem, 0, sizeof(m_pItem));
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize()
{
	CItem*		pItem = new CItem("초급검", 10, 0, 1000);
	pItem->Set_Type(IT_WEAPON);
	m_pItem[IT_WEAPON][BEGINNER]	= pItem;

	pItem = new CItem("중급검", 20, 0, 2000);
	pItem->Set_Type(IT_WEAPON);
	m_pItem[IT_WEAPON][NORMAL] = pItem;

	pItem = new CItem("고급검", 30, 0, 3000);
	pItem->Set_Type(IT_WEAPON);
	m_pItem[IT_WEAPON][RARE] = pItem;

	pItem = new CItem("초급옷", 0, 10, 1000);
	pItem->Set_Type(IT_ARMOR);
	m_pItem[IT_ARMOR][BEGINNER] = pItem;

	pItem = new CItem("중급옷", 0, 20, 2000);
	pItem->Set_Type(IT_ARMOR);
	m_pItem[IT_ARMOR][NORMAL] = pItem;

	pItem = new CItem("고급옷", 0, 30, 3000);
	pItem->Set_Type(IT_ARMOR);
	m_pItem[IT_ARMOR][RARE] = pItem;
}

void CStore::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 초급 2. 중급 3. 고급 4. 판매 5. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(BEGINNER);
			break;
		case 2:
			Render(NORMAL);
			break;

		case 3:
			Render(RARE);
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

void CStore::Render(ITEMCLASS eClass)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		m_pItem[IT_WEAPON][eClass]->Render();
		m_pItem[IT_ARMOR][eClass]->Render();

		cout << "1. 무기 구매 2. 방어구 구매 3. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Buy_Item(m_pItem[IT_WEAPON][eClass]);
			break;

		case 2:
			Buy_Item(m_pItem[IT_ARMOR][eClass]);
			break;

		case 3:
			return;
		}

	}

}

void CStore::Release()
{
	for (size_t i = 0; i < IT_END; ++i)
	{
		for (size_t j = 0; j < CLASS_END; ++j)
		{
			SAFE_DELETE(m_pItem[i][j]);
		}
	}
}

void CStore::Buy_Item(CObj * pItem)
{
	if (m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney &&
		m_pInven->Buy_Item(pItem))
	{
		cout << "구매 성공" << endl;
		dynamic_cast<CPlayer*>(m_pPlayer)->Set_Money(-pItem->Get_Info().iMoney);
	}
	else
		cout << "잔액이 부족합니다" << endl;

	system("pause");

}

void CStore::Sell_Item()
{
	int	iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();
		m_pInven->Render();

		cout << "0. 나가기 " << endl;
		cout << "------------------------------" << endl;
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if (5 <= iInput)
			return;

		int iMoney(0);

		if (m_pInven->Sell_Item(iInput, &iMoney))
		{
			dynamic_cast<CPlayer*>(m_pPlayer)->Set_Money(iMoney);
			cout << "판매 성공" << endl;
		}
		else
			cout << "판매 실패" << endl;
	}
}
