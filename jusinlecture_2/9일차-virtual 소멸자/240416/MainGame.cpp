#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame() : m_pStore(nullptr)
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
}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. ����� 2. ���� 3. ���� : ";
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
			return;
		}

		system("pause");
	}

}

void CMainGame::Release()
{
	SAFE_DELETE(m_pStore);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}
