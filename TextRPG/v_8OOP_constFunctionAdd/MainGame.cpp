#include "MainGame.h"
#include "stdafx.h"
#include "CPlayer.h"
#include "Field.h"

MainGame::MainGame()
{
	m_pPlayer = nullptr;
	m_Field = nullptr;
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
	if (!m_Field)
	{
		m_Field = new CField;
	}
}

void MainGame::Update()
{
	if (m_pPlayer)
	{
		m_pPlayer->SelectJob();
	}
	if (m_Field)
	{
		m_Field->Initialize();
		m_Field->Set_Player(m_pPlayer);
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
			if (m_Field)
				m_Field->Update();
			break;

		case 2:
			return;
		}
		//system("pause");
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_Field);
}
