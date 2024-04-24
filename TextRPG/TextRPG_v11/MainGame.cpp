#include "stdafx.h"
#include "Define.h"
#include "MainGame.h"
#include "Character.h"
#include "CPlayer.h"
#include "ItemBase.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "CStore.h"
MainGame::MainGame() :m_Player(nullptr), m_pStore(nullptr) //m_pFiled(nullptr), 
{
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if (!m_Player)
	{
		m_Player = new CPlayer;
		static_cast<CPlayer*>(m_Player)->SelectJob();
	}
	if (!m_pStore)
	{
		m_pStore = new CStore;
	}
}

void MainGame::Update()
{
	int iInput(0);
	//���� ������
	/*ItemBase* temp = new CWeapon("sample", 1, 0, 3);
	ItemBase* temp2 = new CArmor("sample2", 0, 7, 7);
	static_cast<CPlayer*>(m_Player)->Add_Item(temp);
	static_cast<CPlayer*>(m_Player)->Add_Item(temp2);*/
	//
	while (true)
	{
		system("cls");
		m_Player->Render();

		cout << "1.����� 2. ���� 3.�κ��丮 ���� 4.����";
		cin >> iInput;
		switch (iInput)
		{
		/*case 1:
			m_pFiled->Initialize();
			m_pFiled->Set_Player(m_pBase);
			m_pFiled->Update();
			break;*/
		case 2:
			m_pStore->Initialize();
			m_pStore->Set_Player(m_Player);
			m_pStore->Update();
			break;
		case 3:
			static_cast<CPlayer*>(m_Player)->Start_Inventory();
			break;
		case 4:
			return;
		}
	}
}

void MainGame::Release()
{
	Safe_Delete(m_Player);
	//Safe_Delete(m_pFiled);
	Safe_Delete(m_pStore);
}
