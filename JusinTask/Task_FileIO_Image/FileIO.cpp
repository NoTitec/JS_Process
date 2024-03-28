
// 1. 텍스트 rpg 저장, 불러오기 만들 것

// - 저장하기는 아무 시점에나 삽입해도 됨
// - 불러오기는 직업을 생성하는 시점에 만들 것

#include "stdafx.h"
typedef struct tagPlayer
{
	char splayerName[20];
	int iHp;
	int iAtk;
}PLAYER, * LPPLAYER;
typedef struct tagMonster
{
	char smonsterName[20];
	int iHp;
	int iAtk;
}MONSTER, * LPMONSTER;

enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	ENDJOBINDEX
};

enum MONSTERINDEX
{
	EASY = 1,
	NORMAL,
	HARD,
	ENDMONSTERINDEX
};

enum Scenes {
	SELECTJOBSCENE,
	FIELDSCENE,
	BATTLESCENE,
	END
};

//직업 선택후 동적생성해서 해당 플레이어 메모리 주소 반환
// 내부서 만들고 시작 주소 반환 방법 함수 동적 v1
LPPLAYER Select_Job();

//플레이어 현재 정보 파일 저장 함수
void Save_Current_Player_Info(LPPLAYER lpplayer);
//게임 코드 은닉용 메인 게임함수
void Main_Game();

//씬 매니져
void SceneManager(int SceneNumber, LPPLAYER* lpplayer);
void SceneManager(int SceneNumber, LPPLAYER* lpplayer, LPMONSTER* lpmonster);

// 직업 선택 씬
void Scene1(LPPLAYER* lpplayer);
// 사냥터 씬
void Scene2(LPPLAYER* lpplayer);
// 전투 씬
void Scene3(LPPLAYER* lpplayer, LPMONSTER* lpmonster);

//몬스터 생성 함수
//외부 포인터자체 인자로 받아서 안에서 할당하는 방법의 함수 동적 v2
void Create_Monster(LPMONSTER* ppInfo, const char* pName, int iAttack, int iHp);
//전투 함수
int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster);
//플레이어 정보 출력 함수
void Print_Player_Info(LPPLAYER);
//몬스터 정보 출력 함수
void Print_Monster_Info(LPMONSTER);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Main_Game();

	return 0;
}
//저장기능 추가--------------------------------------------------------------
void Save_Current_Player_Info(LPPLAYER lpplayer)
{

	FILE* pFile = NULL;

	errno_t		err = fopen_s(&pFile, "./Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(lpplayer, sizeof(PLAYER), 1, pFile);
		// fwrite(iArray, sizeof(int), 5, pFile);

		cout << "저장 성공" << endl;

		fclose(pFile);	// 3단계
		system("pause");
		return;
	}
	else
	{
		cout << "파일 개방 실패" << endl;
		system("pause");
	}
}

void Main_Game()
{
	//메인 플레이어 가르키는 포인터
	LPPLAYER lpplayer(nullptr);

	//직업 선택 씬
	SceneManager(SELECTJOBSCENE, &lpplayer);
	//직업선택했는데 여전히 lplayer가 nullptr이면 비정상이므로 종료
	if (lpplayer == nullptr)
	{
		cout << "플레이어 생성 오류" << endl;
		system("pause");
		return;
	}
	//사냥터 씬
	SceneManager(FIELDSCENE, &lpplayer);

	//게임종료전 플레이어 메모리 반환
	//if (pPlayer)
	if (nullptr != lpplayer)
	{
		delete lpplayer;
		lpplayer = nullptr;
	}
	return;
}
//플레이어 힙메모리 할당하고 시작 주소 반환함수(세이브 파일 입출력 추가)--------------------------------------------------------
LPPLAYER Select_Job()
{
	//세이브 파일 불러오기 시도

	FILE* pLoadFile = NULL;

	LPPLAYER pTemp = new PLAYER;

	errno_t		err = fopen_s(&pLoadFile, "./Data/Save.txt", "rb");

	if (0 == err)
	{
		fread(pTemp, sizeof(PLAYER), 1, pLoadFile);
		// fwrite(iTemp, sizeof(int), 5, pLoadFile);

		cout << "불러오기 성공" << endl;
		cout << "-------------" << endl;
		system("pause");
		
		fclose(pLoadFile);	// 3단계
		return pTemp;
	}
	//세이브 없으면 새로 플레이어 만들어서 파일 저장하고 반환하고 종료
	else
	{
		cout << "세이브 없음 새로 생성" << endl;

		LPPLAYER lpTemp = nullptr;
		int		iInput(0);
		bool	bContinue(false);

		while (!bContinue)
		{
			cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 종료) : ";
			cin >> iInput;

			switch (iInput)
			{
			case WARRIOR:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "전사");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case WIZARD:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "마법사");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case THIEF:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "도적");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case ENDJOBINDEX:
				cout << "게임을 종료합니다" << endl;
				bContinue = true;
				break;

			default:
				cout << "잘못 입력하셨습니다" << endl;
				break;
			}
		}

		FILE* pFile = NULL;

		errno_t		err = fopen_s(&pFile, "./Data/Save.txt", "wb");

		if (0 == err)
		{
			fwrite(lpTemp, sizeof(PLAYER), 1, pFile);
			// fwrite(iArray, sizeof(int), 5, pFile);

			cout << "저장 성공" << endl;

			fclose(pFile);	// 3단계
			return lpTemp;
		}
		else
		{
			cout << "파일 개방 실패" << endl;
		}
	}

	
}

//플레이어만 연관있는 씬 메니저
void SceneManager(int SceneNumber, LPPLAYER* lpplayer)
{
	switch (SceneNumber)
	{
	case SELECTJOBSCENE:
		Scene1(lpplayer);
		break;
	case FIELDSCENE:
		Scene2(lpplayer);
		break;
	}
}
//플레이어와 몬스터 연관있는 씬 메니저
void SceneManager(int SceneNumber, LPPLAYER* lpplayer, LPMONSTER* lpmonster)
{
	switch (SceneNumber)
	{
	case BATTLESCENE:
		Scene3(lpplayer, lpmonster);
	}
}
//직업 선택 씬 처리 함수
//인자는 플레이어 이중주소 타입
void Scene1(LPPLAYER* lpplayer)
{//플레이어 타입 포인터가 할당한 힙메모리 가르키도록
	*lpplayer = Select_Job();
}

//사냥터 씬 처리 함수
//인자는 플레이어 이중주소 타입
void Scene2(LPPLAYER* lpplayer)
{
	int		iInput(0);
	LPMONSTER pMonster = nullptr;

	while (true)
	{
		system("cls");
		//이미 lpplayer가 주소값이므로 *붙여서 다시 포인터를 넘겨야함()
		Print_Player_Info(*lpplayer);

		cout << "1. 초급 2. 중급 3. 고급 4. 현재 플레이어 정보 저장 5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Monster(&pMonster, "초급", 3, 30);
			break;

		case 2:
			//Create_Monster(&pMonster, "중급", 6, 60);
			break;

		case 3:
			Create_Monster(&pMonster, "고급", 9, 90);
			break;
		case 4:
			Save_Current_Player_Info(*lpplayer);
			break;
		case 5:
			return;
		}
		//몬스터생성 제대로안됐으면 다시 선택생성메뉴 복귀
		if (pMonster == nullptr)
		{
			continue;
		}
		SceneManager(BATTLESCENE, lpplayer, &pMonster);

	}

}

void Scene3(LPPLAYER* lpplayer, LPMONSTER* lpmonster)
{
	int iResult = Battle(*lpplayer, *lpmonster);

	if (1 == iResult)
	{
		(*lpplayer)->iHp = 100;
	}

	if (nullptr != *lpmonster)
	{
		delete* lpmonster;
		*lpmonster = nullptr;
	}
}

void Create_Monster(LPMONSTER* ppMonster, const char* pName, int iAttack, int iHp)
{
	(*ppMonster) = new MONSTER;
	strcpy_s((*ppMonster)->smonsterName, sizeof((*ppMonster)->smonsterName), pName);
	(*ppMonster)->iHp = iHp;
	(*ppMonster)->iAtk = iAttack;
}

int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster)
{
	int iInput(0);

	while (true)
	{
		system("cls");

		Print_Player_Info(lpplayer);
		Print_Monster_Info(lpmonster);

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			lpmonster->iHp -= lpplayer->iAtk;
			lpplayer->iHp -= lpmonster->iAtk;

			if (0 >= lpplayer->iHp)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}

			if (0 >= lpmonster->iHp)
			{
				cout << "승리" << endl;
				system("pause");
				return 0;
			}
		}

		else if (2 == iInput)
			return 0;
	}
}

void Print_Player_Info(LPPLAYER lpplayer)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << lpplayer->splayerName << endl;
	cout << "체력 : " << lpplayer->iHp << "\t공격력 : " << lpplayer->iAtk << endl;
}
void Print_Monster_Info(LPMONSTER lpmonster)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << lpmonster->smonsterName << endl;
	cout << "체력 : " << lpmonster->iHp << "\t공격력 : " << lpmonster->iAtk << endl;
}