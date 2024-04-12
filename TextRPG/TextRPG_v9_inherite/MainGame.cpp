#include "MainGame.h"
#include "stdafx.h"
#include "CPlayer.h"
#include "CField.h"

MainGame::MainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
	}
	if (!m_pField)
	{
		m_pField = new CField;
	}
}

void MainGame::Update()
{
	if (m_pPlayer)
	{
		m_pPlayer->SelectJob();
	}
	if (m_pField)
	{
		m_pField->Initialize();
		m_pField->Set_Player(m_pPlayer);
	}

	int iInput(0);

	while (true)
	{
		system("cls");
		//����ڵ� �ۼ����ϸ� �������Ѵٰ� �����ߴµ� ���̷� �����δ� ��� ���� ����
		if (m_pPlayer)
		{
			m_pPlayer->Render();
		}
		cout << "1. ����� ���� 2. ���� ���� :";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (m_pField)
				m_pField->Update();
			break;

		case 2:
			return;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
}
