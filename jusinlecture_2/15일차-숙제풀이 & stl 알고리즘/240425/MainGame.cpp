#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame() : m_pStore(nullptr), m_pInven(nullptr)
{
	m_pPlayer = nullptr;
	m_pField = nullptr;

}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pPlayer)	// if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->SelectJob();
	}

	if(!m_pField)
	{
		m_pField = new CField;
		m_pField->Initialize();
	}

	m_pField->Set_Player(m_pPlayer);

	if (!m_pStore)
	{
		m_pStore = new CStore;
		m_pStore->Initialize();
	}

	m_pStore->Set_Player(m_pPlayer);

	if (!m_pInven)
	{
		m_pInven = new CInven;
		m_pInven->Initialize();
	}

	m_pInven->Set_Player(m_pPlayer);
	m_pStore->Set_Inven(m_pInven);

}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (m_pField)
				m_pField->Update();

			break;

		case 2:
			if (m_pStore)
				m_pStore->Update();
			break;

		case 3:
			if (m_pInven)
				m_pInven->Update();
			break;

		case 4:
			return;
		}

		system("pause");
	}

}

void CMainGame::Release()
{
	Safe_Delete<CInven*>(m_pInven);
	SAFE_DELETE(m_pStore);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}
