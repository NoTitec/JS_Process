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
		//방어코드 작성안하면 역참조한다고 오류뜨는데 왜이럼 실제로는 없어도 문제 없음
		if (m_pPlayer)
		{
			m_pPlayer->Render();
		}
		cout << "1. 사냥터 진입 2. 게임 종료 :";
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
