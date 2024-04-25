#include "stdafx.h"
#include "Inven.h"
#include "Item.h"


CInven::CInven() : m_iSize(5)
{
}


CInven::~CInven()
{
	Release();
}

bool CInven::Buy_Item(CObj* pItem)
{
	if (m_vecInven.size() >= m_iSize)
		return false;

	CItem*	pCopy = dynamic_cast<CItem*>(pItem);

	CObj*	pBuyItem = new CItem(*pCopy);

	m_vecInven.push_back(pBuyItem);

	return true;
}

bool CInven::Sell_Item(int iIndex, int * pMoney)
{
	vector<CObj*>::iterator		iter = m_vecInven.begin();

	iter += iIndex;

	*pMoney = (*iter)->Get_Info().iMoney >> 1;

	Safe_Delete<CObj*>(*iter);
	m_vecInven.erase(iter);

	return true;
}

void CInven::Initialize()
{
}

void CInven::Update()
{
	int		iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();
		cout << "1. 장착 2. 해제 3. 나가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Equip_Item();
			break;

		case 2:
			Unequip_Item();
			break;

		case 3:
			return;
		}
		system("pause");
	}

}

void CInven::Render()
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		cout << i + 1 << ". ";
		m_vecInven[i]->Render();
	}
}

void CInven::Release()
{
	for_each(m_vecInven.begin(), m_vecInven.end(), DeleteObj());
	m_vecInven.clear();
}

void CInven::Equip_Item()
{
	int	iInput(0);

	while(true)
	{
		system("cls");
		
		m_pPlayer->Render();
		Render();

		cout << "0. 나가기 : ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if((size_t)iInput >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Equip_Item(m_vecInven[iInput]);
	}

}

void CInven::Unequip_Item()
{
	int	iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();
		Render();

		cout << "0. 나가기 : ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if ((size_t)iInput >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Unequip_Item(m_vecInven[iInput]);
	}
}
