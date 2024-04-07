#include "stdafx.h"
#include <fstream>
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	LOAD,
	END
};
enum DIFFICULTY
{
	EASY=1,
	NORMAL,
	HARD
};
//필요 함수 목록

#pragma region 플레이어 함수
//직업 선택하고 해당 플레이어 인스턴스를 동적 생성 후 주소 반환하는 함수
LPPLAYER Make_Player();
//필요한 플레이어 정보 인자로 받아 동적 할당한 플레이어 메모리에 정보 채우는 함수
void Create_Player(LPPLAYER* lpplayer, const char* pName, int iAtk, int iHp);
void Print_Player_Info(LPPLAYER lpplayer);
#pragma endregion 플레이어 함수

#pragma region 몬스터 함수
void Create_Monster(LPMONSTER* lpmonster, const char* pName, int iAtk, int iHp);
void Print_Monster_Info(LPMONSTER lpmonster);
#pragma endregion 몬스터 함수

#pragma region 파일입출력함수
bool Save_Player_Data(LPPLAYER lplayer);
bool Load_Player_Data(LPPLAYER* lpplayer);
#pragma endregion 파일입출력함수
//게임 시작 함수
void Game_Start(LPPLAYER lpplayer);

//플레이어와 몬스터의 전투 후 결과 반환
int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster);


///////////////////////////////////////////////////////
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	LPPLAYER player = Make_Player();

	if (player == nullptr)
	{
		return -1;
	}

	Game_Start(player);

	SAFE_DELETE(player)
	return 0;
}

LPPLAYER Make_Player()
{

	LPPLAYER lpplayer = nullptr;
	int iInput(0);
	bool bContinue(false);

	while (!bContinue)
	{
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료) : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Create_Player(&lpplayer,"전사",10,100);
			bContinue = true;

			break;

		case WIZARD:
			Create_Player(&lpplayer, "마법사", 10, 100);
			bContinue = true;

			break;

		case THIEF:
			Create_Player(&lpplayer, "도적", 10, 100);
			bContinue = true;

			break;

		case LOAD:
			bContinue=Load_Player_Data(&lpplayer);
			

			break;

		default:
			cout << "Wrong Input Man~~~"<<endl;
			break;
		}

	}
	return lpplayer;
}

void Create_Player(LPPLAYER* lpplayer, const char* pName, int iAtk, int iHp)
{
	(*lpplayer) = new PLAYER;

	strcpy_s((*lpplayer)->szName, sizeof((*lpplayer)->szName), pName);
	(*lpplayer)->iAtk = iAtk;
	(*lpplayer)->iHp = iHp;
}

void Print_Player_Info(LPPLAYER lpplayer)
{
	cout<<"이름 : " << lpplayer->szName << endl;
	cout<<"체력 : " << lpplayer->iHp << endl;
	cout<<"공격력 : " << lpplayer->iAtk << endl;
}

void Create_Monster(LPMONSTER* lpmonster, const char* pName, int iAtk, int iHp)
{
	(*lpmonster) = new MONSTER;
	strcpy_s((*lpmonster)->szName, sizeof((*lpmonster)->szName), pName);
	(*lpmonster)->iAtk = iAtk;
	(*lpmonster)->iHp = iHp;
}

void Print_Monster_Info(LPMONSTER lpmonster)
{
	cout << "이름 : " << lpmonster->szName << endl;
	cout << "체력 : " << lpmonster->iHp << endl;
	cout << "공격력 : " << lpmonster->iAtk << endl;
}

bool Save_Player_Data(LPPLAYER lplayer)
{
	FILE* pFile = nullptr;
	if (0 == fopen_s(&pFile, "./Data/Save.txt", "wb"))
	{
		fwrite(lplayer, sizeof(PLAYER), 1, pFile);
		cout << "저장 완료" << endl;

		fclose(pFile);
		return true;
	}
	else
	{
		cout << "저장 실패" << endl;
		return false;
	}
}

bool Load_Player_Data(LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;
	ifstream readFile;
	readFile.open("./Data/Save.txt");
	if (readFile.is_open())
	{
		readFile.read((char*)(*lpplayer),sizeof(PLAYER));
		cout << "불러오기 성공" << endl;
		readFile.close();
		return true;
	}
	else
	{
		cout << "불러오기 실패" << endl;
		return false;
	}
	/*(*lpplayer) = new PLAYER;
	FILE* pFile = nullptr;
	if (0 == fopen_s(&pFile, "./Data/Save.txt", "rb"))
	{
		fread((*lpplayer), sizeof(PLAYER), 1, pFile);
		cout << "불러오기 성공" << endl;
		fclose(pFile);
		return true;
	}
	else
	{
		cout << "불러오기 실패" << endl;
		return false;
	}*/
}

void Game_Start(LPPLAYER lpplayer)
{
	int iInput(0);
	LPMONSTER lpmonster = nullptr;
	bool bCheckSaveOk = false;

	while (true)
	{
		system("cls");
		Print_Player_Info(lpplayer);
		cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			Create_Monster(&lpmonster, "초급", 3, 30);
			break;

		case NORMAL:
			Create_Monster(&lpmonster, "중급", 6, 60);

			break;
		case HARD:
			Create_Monster(&lpmonster, "고급", 9, 90);

			break;
		case 4:
			bCheckSaveOk=Save_Player_Data(lpplayer);
			system("pause");
			break;
			//5번누를시 게임 종료
		case 5:
			SAFE_DELETE(lpmonster)
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
		int BattleResult = Battle(lpplayer, lpmonster);
		if (1 == BattleResult)
		{
			lpplayer->iHp = 100;
		}
		//죽었든 이겼든 도망쳤든 전투 끝났으므로 생성했던 몬스터 힙메모리 해제하고 nullptr 초기화
		SAFE_DELETE(lpmonster)
	}
}

int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster)
{
	int iInput(0);

	//플레이어, 몬스터가 죽거나 도망칠때까지 무한 반복
	//플레이어 승리-> 0
	//플레이어 사망-> 1
	//플레이어 도망-> 2
	while (true)
	{
		system("cls");
		Print_Player_Info(lpplayer);
		Print_Monster_Info(lpmonster);

		cout << "1. 공격 2. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			lpplayer->iHp -= lpmonster->iAtk;
			lpmonster->iHp -= lpplayer->iAtk;
			if (0 >= lpplayer->iHp)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}
			if (0 >= lpmonster->iHp)
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
			cout << "you input wrong bro~~~~"<<endl;
		}
	}
	return 0;
}
