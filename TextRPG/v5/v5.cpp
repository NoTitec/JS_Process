#include "stdafx.h"
//맵 크기 상수
const int mapSize = 15;
//씬 메니저 관리용 int 전역변수
int iSceneNumber(0);
//맵 메모리 위치기록용 포인터
//플레이어 좌표는 -1로 표기
int** mapArray;
//게임 종료 좌표 (맵 우하단)
int iendx = mapSize - 1;
int iendy = mapSize - 1;

//무기 구조체
typedef struct tagWeapon
{
	char szWeaponName[20];
	int Atk;
} WEAPON, * LPWEAPON;

//플레이어 구조체
typedef struct tagPlayer
{
	char szName[20];
	int iHp;
	int iCurrentLocation[2];//row,col
	WEAPON weapon;
} PLAYER, * LPPLAYER;
//플레이어 정보용 전역포인터
LPPLAYER lpplayer=nullptr;

//좀비 구조체
typedef struct tagZombie
{
	char szDifficulty[20];
	int iHp;
	int iAtk;
}ZOMBIE, * LPZOMBIE;
//씬 열거체
enum Scenes
{
	MAINSCENE,
	MOVESCENE,
	SELECTJOB,
	END
};
//난이도 열거체
enum Diffeculty {
	EASY,
	NORMAL,
	HARD
};
//함수 정의 부----------------------------------------------------
//메인 게임 시작 함수
void Main_Game();
//---------------------------
//씬 메니저
void SceneManager(int Scenenumber);
//----------------------------------------
//씬 함수들
// 
//메인 씬
void StartScene();
//이동 씬
void Move_Scene(LPPLAYER lpplayer);
//플레이어 생성 씬
void Make_Player_Scene(LPPLAYER* lpplayer);
//맵 초기화 함수
void ResetMap(int** Array);

//맵 상태 출력
void Print_map(int** Array, int size);
//플레이어 정보 출력
void Print_Player(LPPLAYER lpplayer);

//플레이어 이동+ 전투
void Move_Player(int** Array, LPPLAYER* lpplayer, int direction);
//현재 맵,플레이어정보 바이너리 파일 저장,로드함수
bool Save_Data(int** Array, LPPLAYER lpplayer);
bool Load_Data(int** Array, LPPLAYER* lpplayer);
//바이너리 파일에서 맵, 플레이어 정보 불러오기 함수
//----------------------------------------------
//실행, 정의부-----------------------------------
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Main_Game();
	return 0;
}

void Print_Player(LPPLAYER lpplayer)
{
	cout << "-----------------------" << endl;
	cout << "직업 : " << lpplayer->szName << endl;
	cout << "체력 : " << lpplayer->iHp << endl;
	cout << "현재 장비 : " << lpplayer->weapon.szWeaponName << endl;
	cout << "장비 공격력 : " << lpplayer->weapon.Atk << endl;
}
void Print_map(int** Array, int size)
{
	cout << "============================" << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (Array[i][j] == -1)
			{
				cout << setw(3) << "*";
			}
			else
			{
				cout << setw(3) << Array[i][j];
			}
		}
		cout << endl;
	}
	cout << "============================" << endl;
}
void Move_Player(int** Array, LPPLAYER* lpplayer,int direction)
{
	//들어온 방향정보로 분기하여 이동가능한지 판별하고 이동 가능한 위치면 해당 위치로 이동시키고
	//만약 해당 위치가 몬스터가있는 1 위치면 전투로 진입하고 0이면 그냥 swap만 수행
	switch (direction)
	{
	case1:
		break;
	case 2:
		break;
	case 3:
		break;

	case 4:
		if (mapSize - 1 == (*lpplayer)->iCurrentLocation[1] % mapSize)
		{
			break;
		}
		if ((Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1] + 1]) == 1)
		{
			cout << "전투진입함수 호출 필요" << endl;
			//여기부터 구현~~~~~~~~~~~~
			system("pause");
			break;
		}
		swap(Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1]], Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1] + 1]);
		(*lpplayer)->iCurrentLocation[1] += 1;
		break;
	}
	return;
}
bool Save_Data(int** Array, LPPLAYER lpplayer)
{
	FILE* pSaveFile = nullptr;

	errno_t		err = fopen_s(&pSaveFile, "./Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(lpplayer, sizeof(PLAYER), 1, pSaveFile);
		// 맵 데이터 저장
		for (int i = 0; i < mapSize; ++i)
		{
			fwrite(Array[i], sizeof(int), mapSize, pSaveFile);
		}

		fclose(pSaveFile);
		return true;
	}

	return false;
}
bool Load_Data(int** Array, LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;

	FILE* pLoadFile = nullptr;

	errno_t err = fopen_s(&pLoadFile, "./Data/Save.txt", "rb");

	if (0 == err)
	{
		fread((*lpplayer), sizeof(PLAYER), 1, pLoadFile);
		// 맵 데이터 로드
		for (int i = 0; i < mapSize; ++i)
		{
			fread(Array[i], sizeof(int), mapSize, pLoadFile);
		}

		fclose(pLoadFile);

		return true;
	}

	return false;
}
void Main_Game()
{
	//난수 시드 설정
	srand(unsigned(time(NULL)));
	//맵용 메모리 동적 할당 후 0초기화
	mapArray = new int* [mapSize];
	for (int i = 0; i < mapSize; ++i)
	{
		mapArray[i] = new int[mapSize];
		memset(mapArray[i], 0, sizeof(int) * mapSize);
	}

	//씬 종료조건 전까지 무한 반복
	while (iSceneNumber != END)
	{
		switch (iSceneNumber)
		{
		case MAINSCENE:
			SceneManager(MAINSCENE);
			break;
		case MOVESCENE:
			SceneManager(MOVESCENE);
			break;
		case SELECTJOB:
			SceneManager(SELECTJOB);
			break;
		}
	}

	//맵 메모리 할당 해제
	for (int i = 0; i < mapSize; ++i)
	{
		delete[] mapArray[i];
	}
	delete[] mapArray;
	if (lpplayer != nullptr)
	{
		delete lpplayer;
	}
	return;
}

void SceneManager(int Scenenumber)
{
	switch (Scenenumber) {
	case MAINSCENE:
		StartScene();
		break;
	case MOVESCENE:
		Move_Scene(lpplayer);
		break;
	case SELECTJOB:
		Make_Player_Scene(&lpplayer);
		break;
	}
	return;
}

//메인 씬 관리 함수
void StartScene()
{
	cout << "-------------  Z City --------------" << endl;
	cout << "1. New Game 2. Load Game 3. Quit" << endl;

	bool bEndStartScene(true);
	int iInput(0);

	while (bEndStartScene)
	{
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			//맵 새로 초기화하고 씬 넘버 직업 선택 넘버로 변경 후 함수 종료
			ResetMap(mapArray);
			Print_map(mapArray, mapSize);
			iSceneNumber = SELECTJOB;
			return;
		case 2:
			//파일에서 맵 정보 불러와서 mapArray에 채우고 플레이어정보도 채우기
			if (Load_Data(mapArray, &lpplayer))
			{
				cout << "로드 성공" << endl;
				iSceneNumber = MOVESCENE;
				system("pause");
				return;
			}
			//파일 없으면 다시 입력
			break;
		case 3:
			iSceneNumber = END;
			bEndStartScene = false;
		}
	}

	return;
}

void ResetMap(int** Array)
{
	//맵 랜덤으로 1또는 0으로 채우기(1~10중에 8이상일때만)
	//1좀비 있는 칸, 0 아무것도 없는 칸

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			int iorigin = rand() % 10;
			if (8 <= iorigin)
				Array[i][j] = 1;
			else
			{
				Array[i][j] = 0;
			}
		}
	}
	Array[0][0] = -1;
}

void Make_Player_Scene(LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;
	LPPLAYER temp = *lpplayer;
	int iInput(0);
	cout << "직업을 선택하세요(1. 학생 2. 군인 3. 칼잡이 ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s((*lpplayer)->szName,sizeof(temp->szName),"학생");
		temp->iHp = 100;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 5;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "방망이");
		break;
	case 2:
		strcpy_s((*lpplayer)->szName, sizeof(temp->szName), "군인");
		temp->iHp = 300;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 15;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "소총");
		break;
	case 3:
		strcpy_s((*lpplayer)->szName, sizeof(temp->szName), "칼잡이");
		temp->iHp = 99999;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 9999;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "식칼");

		break;
	}
	iSceneNumber = MOVESCENE;
	return;
}

void Move_Scene(LPPLAYER lpplayer)
{
	//1.상 2.하 3.좌. 도 구현필요~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//게임 종료 조건 테스트위해 하만 구현하고 나머진 나중에
	system("cls");
	Print_map(mapArray,mapSize);
	Print_Player(lpplayer);
	cout << "--------------------------" << endl;
	cout << "1.상 2.하 3.좌 4.우 5.저장 6.메인메뉴" << endl;
	int iInput(0);
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		cout << "상이동" << endl;
		break;
	case 2:
		cout << "하이동" << endl;
		break;
	case 3:
		cout << "좌이동" << endl;
		break;
	case 4:
		Move_Player(mapArray,&lpplayer,iInput);
		break;
	case 5:
		cout << "저장" << endl;
		if (Save_Data(mapArray, lpplayer))
		{
			cout << "저장 성공" << endl;
			system("pause");
		}
		break;
	case 6:
		iSceneNumber = MAINSCENE;
		return;
	}
}
