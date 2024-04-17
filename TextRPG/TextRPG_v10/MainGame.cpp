#include "MainGame.h"
#include "stdafx.h"
#include "CField.h"
#include "CStore.h"

CMainGame::CMainGame() :m_pBase(nullptr),m_pFiled(nullptr),m_pStore(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pBase)
	{
		m_pBase = new CPlayer;
		static_cast<CPlayer*>(m_pBase)->SelectJob();
	}
	if (!m_pFiled)
	{
		m_pFiled = new CField;
	}
	if (!m_pStore)
	{
		m_pStore = new CStore;
	}
}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pBase->Render();

		cout << "1.사냥터 2. 상점 3.종료";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pFiled->Initialize();
			m_pFiled->Set_Player(m_pBase);
			m_pFiled->Update();
			break;
		case 2:
			m_pStore->Initialize();
			m_pStore->Set_Player(m_pBase);
			m_pStore->Update();
			break;
		case 3:
			return;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pBase);
	SAFE_DELETE(m_pFiled);
	SAFE_DELETE(m_pStore);
}
