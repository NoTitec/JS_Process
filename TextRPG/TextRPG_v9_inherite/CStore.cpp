#include "stdafx.h"
#include "CStore.h"
#include "CPlayer.h"

CStore::CStore()
{
	m_pPlayer = nullptr;
}

CStore::~CStore()
{
	Release();
}

void CStore::Set_Player(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::Initialize()
{

}

void CStore::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.초급아이템 2.중급아이템 3.고급아이템 4.나가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pPlayer->SetItem("초급아이템");
			cout << "초급아이템 구매완료" << endl;
			system("pause");
			break;
		case 2:
			m_pPlayer->SetItem("중급아이템");
			cout << "중급아이템 구매완료" << endl;
			system("pause");
			break;
		case 3:
			m_pPlayer->SetItem("고급아이템");
			cout << "초급아이템 구매완료" << endl;
			system("pause");
			break;
		case 4:
			return;
		}
	}
}

void CStore::Release()
{
	
}
