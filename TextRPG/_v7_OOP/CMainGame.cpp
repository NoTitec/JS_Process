#include "CMainGame.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "stdafx.h"

enum DIFFICULTY
{
	EASY = 1,
	NORMAL,
	HARD
};
CMainGame::CMainGame()
{
	m_Player = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

//게임 시작 후 플레이어 객체 생성하고 성공시 true, 실패시 false 반환
bool CMainGame::Initialize()
{
	m_Player = new CPlayer;
	int iInput(0);
	bool bContinue(false);

	while (!bContinue)
	{
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료) : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			m_Player->Initialize("전사", 10, 100);
			bContinue = true;

			break;

		case WIZARD:
			m_Player->Initialize("마법사", 10, 100);
			bContinue = true;

			break;

		case THIEF:
			m_Player->Initialize("도적", 10, 100);
			bContinue = true;

			break;

		case LOAD:
			bContinue = m_Player->Load_Player_Data();


			break;

		default:
			cout << "Wrong Input Man~~~" << endl;
			break;
		}
	}

	if (m_Player)
	{
		return true;
	}
	cout << "플레이어 객체 생성 실패" << endl;
	system("pause");
	return false;
}

void CMainGame::Update()
{
	int iInput(0);
	bool bCheckSaveOk = false;

	while (true)
	{
		system("cls");
		CMonster* pMonster = new CMonster;
		m_Player->Print_Player_Info();
		cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			pMonster->Initialize("초급", 3, 30);
			break;

		case NORMAL:
			pMonster->Initialize("중급", 6, 60);

			break;
		case HARD:
			pMonster->Initialize("고급", 12, 90);

			break;
		case 4:
			bCheckSaveOk = m_Player->Save_Player_Data();
			system("pause");
			break;
			//5번누를시 게임 종료
		case 5:
			SAFE_DELETE(pMonster)
				return;

		default:
			cout << "you Input wrong Number Boy~~~~" << endl;

		}
		//메뉴서 저장눌렀으면 데이터 불러오고 다시 난이도 선택메뉴로 돌아가기
		if (bCheckSaveOk)
		{
			bCheckSaveOk = false;
			continue;
		}
		//몬스터 생성했으면 전투 진입
		int BattleResult = Battle(m_Player, pMonster);
		if (1 == BattleResult)
		{
			m_Player->Set_Hp(100);
		}
		//죽었든 이겼든 도망쳤든 전투 끝났으므로 생성했던 몬스터 힙메모리 해제하고 nullptr 초기화
		SAFE_DELETE(pMonster)
	}
}

int CMainGame::Battle(CPlayer* player, CMonster* monster)
{
	int iInput(0);

	//플레이어, 몬스터가 죽거나 도망칠때까지 무한 반복
	//플레이어 승리-> 0
	//플레이어 사망-> 1
	//플레이어 도망-> 2
	while (true)
	{
		system("cls");
		player->Print_Player_Info();
		monster->Print_Monster_Info();
		cout << "1. 공격 2. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			player->Take_Damage(monster->Get_Atk());
			monster->Take_Damage(player->Get_Atk());
			if (0 >= player->Get_Hp())
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}
			if (0 >= monster->Get_Hp())
			{
				cout << "몬스터 퇴치" << endl;
				cout << "승리" << endl;
				system("pause");
				return 0;
			}
			break;
		case 2:
			return 2;
		default:
			cout << "you input wrong bro~~~~" << endl;
		}
	}
	return 0;
}

void CMainGame::Release()
{
	SAFE_DELETE(m_Player);
}
