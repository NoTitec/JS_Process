#include "MainGame.h"
#include "Define.h"
#include "Character.h"
#include "CPlayer.h"
#include "stdafx.h"
#include "ItemBase.h"
#include "CWeapon.h"
MainGame::MainGame() :m_Player(nullptr), m_pFiled(nullptr), m_pStore(nullptr)
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
}

void MainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_Player->Render();

		cout << "1.사냥터 2. 상점 3.종료 4.아이템 추가 테스트";
		cin >> iInput;
		switch (iInput)
		{
		/*case 1:
			m_pFiled->Initialize();
			m_pFiled->Set_Player(m_pBase);
			m_pFiled->Update();
			break;
		case 2:
			m_pStore->Initialize();
			m_pStore->Set_Player(m_pBase);
			m_pStore->Update();
			break;*/
		case 3:
			return;
		case 4:
			ItemBase * temp = new CWeapon("sample",1,2,3);
			ItemBase* temp2 = new CWeapon("sample2", 7, 7, 7);
			static_cast<CPlayer*>(m_Player)->Add_Item(temp);
			static_cast<CPlayer*>(m_Player)->Add_Item(temp);

			static_cast<CPlayer*>(m_Player)->Render_Inventory();
			system("pause");
		}
	}
}

void MainGame::Release()
{
	Safe_Delete(m_Player);
	Safe_Delete(m_pFiled);
	Safe_Delete(m_pStore);
}
