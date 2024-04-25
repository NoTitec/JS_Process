#include "CMainGame.h"
#include "Character.h"
#include "Player.h"
#include "CStore.h"
#include "CInventory.h"

MainGame::MainGame():m_pPlayer(nullptr),m_pInventory(nullptr),m_pStore(nullptr)
{
}

MainGame::~MainGame()
{
	Safe_Delete(m_pPlayer);
	Safe_Delete(m_pInventory);
	Safe_Delete(m_pStore);
}

void MainGame::Initialize()
{
	//플레이어 생성
	m_pPlayer = new Player;
	static_cast<Player*>(m_pPlayer)->Select_Job();
	//상점생성
	m_pStore = new CStore;
	m_pStore->Initialize();
	m_pStore->Set_Player(m_pPlayer);
	//인벤토리 생성
	m_pInventory = new CInventory;
	m_pInventory->Initialize();
	m_pInventory->Set_Player(m_pPlayer);

	//상점에 인벤토리 넣기
	m_pStore->Set_Inventory(m_pInventory);
}

void MainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "2. 상점 3. 인벤토리 4. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{

		case 2:
			if (m_pStore)
				m_pStore->Update();
			break;

		case 3:
			if (m_pInventory)
				m_pInventory->Update();
			break;

		case 4:
			return;
		}

		system("pause");
	}
}

void MainGame::Release()
{
	Safe_Delete<CInventory*>(m_pInventory);
	Safe_Delete<CStore*>(m_pStore);
	Safe_Delete<Character*>(m_pPlayer);
}
