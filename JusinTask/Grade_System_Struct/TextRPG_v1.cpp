#include <iostream>

using namespace std;

//플레이어 정보 구조체 정의
typedef struct tagPlayer {
	char s_Name[20];
	int iHp;
	int iAtk;
}PLAYER,*LPPLAYER;

//몬스터 정보 구조체 정의
typedef struct tagMonster {
	char s_Name[20];
	int iHp;
	int iAtk;
}MONSTER,*LPMONSTER;

//플레이어 직업정보 저장할 구조체
//PLAYER tPlayerArray[3] = {};
//플레이어 인스턴스
PLAYER tPlayer = {};
//플레이어 인스턴스 가르키는 포인터
LPPLAYER ptPlayer = &tPlayer;

//몬스터 정보 저장할 구조체
//MONSTER tMonsterArray[3] = {};
//몬스터 인스턴스
MONSTER tMonster = {};
//몬스터 인스턴스 가르키는 포인터
LPMONSTER ptMonster= &tMonster;

//게임 종료 제어 bool 변수(Stage 1)
bool bEndGame(true);
//stage2 제어 bool 변수
bool bEndStage2(true);
//게임 정보 초기화하고 직업 선택하는 함수
void InitGame();
//플레이어 정보 출력 함수
void Print_Player_Status(LPPLAYER lpplayer);
//전투 함수
void Start_Battle(int idiffecult);

int main()
{
	InitGame();
	//사망해도 직업선택창으로 돌아가지는 않으므로 직업선택후 초기정보 저장하고있어야 불러올수있음
	//설계단계 때 누락됨
	PLAYER tbackupPlayer;
	strcpy_s(tbackupPlayer.s_Name, sizeof(tbackupPlayer.s_Name), ptPlayer->s_Name);
	tbackupPlayer.iHp = ptPlayer->iHp;
	tbackupPlayer.iAtk = ptPlayer->iAtk;

	while (bEndGame)
	{
		//stage 1
		int iStage1Input(0);
		if (ptPlayer->iHp == 0)
		{
			strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), tbackupPlayer.s_Name);
			ptPlayer->iHp = tbackupPlayer.iHp;
			ptPlayer->iAtk = tbackupPlayer.iAtk;
		}
		Print_Player_Status(ptPlayer);
		cout << "1. 사냥터 2. 종료 :";
		cin >> iStage1Input;
		if (iStage1Input == 2)
		{
			system("cls");
			return 0;
		}
		else
		{
			bEndStage2 = true;
			//stage 2
			while (bEndStage2)
			{
				int iStage2Input(0);
				Print_Player_Status(ptPlayer);
				cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 :";
				cin >> iStage2Input;
				if (iStage2Input == 4)
				{
					//= 이 ==이 되어있네 개쓰레기 키보드 ㄹㅇ
					bEndStage2 = false;
				}
				else if(iStage2Input==1)
				{
					Start_Battle(iStage2Input);
				}
				else if (iStage2Input == 2)
				{
					Start_Battle(iStage2Input);
				}
				else if (iStage2Input == 3)
				{
					Start_Battle(iStage2Input);
				}
				else
				{
					cout << "잘못된 입력" << endl;
				}
			}
		}
	}
	return 0;
}

void InitGame()
{
	int iInput(0);
	cout << "==============================================" << endl;
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) :" << endl;

	char cJobArray[3][20] = {"전사","마법사","도적"};
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	case 2:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	case 3:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	default:
		cout << "잘못된 입력";
		break;
	}
}

void Print_Player_Status(LPPLAYER lpplayer)
{
	system("cls");
	cout << "==============================================" << endl;
	cout << "이름 : " << lpplayer->s_Name << endl;
	cout << "체력 : " << lpplayer->iHp << "\t공격력 : " << lpplayer->iAtk << endl;
}
void Print_Monster_Status(LPMONSTER lpmonster)
{
	//system("cls");
	cout << "==============================================" << endl;
	cout << "이름 : " << lpmonster->s_Name << endl;
	cout << "체력 : " << lpmonster->iHp << "\t공격력 : " << lpmonster->iAtk << endl;
}
void Start_Battle(int idiffecult)
{
	bool bBattleEnd(true);
	//들어온 난이도 따라 몬스터 생성
	char cMonsterNameArray[3][20] = { "초급","중급","고급" };
	switch (idiffecult)
	{
	case 1:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 30;
		ptMonster->iAtk = 3;
		break;
	case 2:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 60;
		ptMonster->iAtk = 6;
		break;
	case 3:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 90;
		ptMonster->iAtk = 9;
		break;

	default:
		cout << "몬스터 잘못 선택" << endl;
		return;
		break;
	}
	//플레이어가 죽거나 승리하거나 도망갈때까지 반복
	while (bBattleEnd)
	{
		int iStage3Input(0);
	//플레이어 정보 출력
		Print_Player_Status(ptPlayer);
	//몬스터 정보 출력
		Print_Monster_Status(ptMonster);
	//공격 도망 선택
		cout << "1. 공격 2. 도망 :";
		cin >> iStage3Input;
	//도망선택하면 몬스터 인스턴스 초기화하고 return
		if (iStage3Input == 2)
		{
			strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), "");
			ptMonster->iHp = 0;
			ptMonster->iAtk = 0;
			return;
		}
	//공격시
		else if(iStage3Input==1)
		{
			int iTmpPlayerHP = (ptPlayer->iHp) - (ptMonster->iAtk);
			//--1. 플레이어 사망 판별 만약 죽었으먼 플레이어 상태 초기 상태로 바꿔주고 bEndstage2 false로 바꿔주고 플레이어 사망 출력 후 return
			if (iTmpPlayerHP <= 0)
			{
				strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), "");
				ptPlayer->iHp = 0;
				ptPlayer->iAtk = 0;
				bEndStage2 = false;
				cout << "플레이어 사망" << endl;
				system("pause");
				return;
			}
			//안죽었으면 플레이어랑 몬스터 서로의 공격력 정보로 데미지 입히기
			else
			{
				//몬스터 피 0보다 작거나 같으면 승리 출력하고 return
				int iTmpMonsterHP = (ptMonster->iHp) - (ptPlayer->iAtk);
				if (iTmpMonsterHP <= 0)
				{
					cout << "승리" << endl;
					system("pause");
					return;
				}
				//플레이어도 몬스터도 안죽은경우
				else
				{
					ptPlayer->iHp -= ptMonster->iAtk;
					ptMonster->iHp -= ptPlayer->iAtk;
				}
			}
		}
	//공격도 도망도아닌 이상한 입력일 경우
		else{
			cout << "잘못된 입력" << endl;
		}
	}
}
