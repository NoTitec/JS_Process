// TextRPG_v2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
using namespace std;

//플레이어 구조체
typedef struct tagPlayer
{
    char	szName[32];
    int		iAttack;
    int		iHp;
}PLAYER, *LPPLAYER;
//몬스터 구조체
typedef struct tagMonster
{
    char	szName[32];
    int		iAttack;
    int		iHp;
}MONSTER, * LPMONSTER;

//몬스터 난이도 열거체
enum Monsters
{
    EASY=1,
    NORMAL,
    HARD
};
//선택한 직업의 플레이어 인스턴스 동적 생성하고 시작 주소반환 함수
LPPLAYER Select_Job();

//플레이어 정보 출력 함수(플레이어 포인터)
void RenderPlayer(LPPLAYER lpPlayer);
//몬스터 정보 출력 함수(몬스터 포인터)
void RenderMonster(LPMONSTER lpMonster);

//사냥터(플레이어 포인터)
void Field(LPPLAYER lpPlayer);
//몬스터 매개변수 난이도에 따라 동적 생성 반환( 난이도 int )
LPMONSTER Create_Monster(int iDifficult);
//전투(폴레이어 포인터, 몬스터 포인터)
void Fight(LPPLAYER lpPlayer, LPMONSTER lpMonster);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//플레이어 포인터
    LPPLAYER mypCharacter=nullptr;
	//직업선택 후 플레이어 정보 초기화
    mypCharacter = Select_Job();

	int iInput(0);
	//종료 누를 때까지 반복
	while (true)
	{
		system("cls");
		RenderPlayer(mypCharacter);

		cout << "1. 사냥터 2. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Field(mypCharacter);
			break;
		case 2:
			//게임 종료 선택시 플레이어 메모리 반환
			delete mypCharacter;
			mypCharacter = nullptr;
			return 0;
		}
	}

    return 0;
}

LPPLAYER Select_Job()
{
	//플레이어 크기 힙 메모리 할당
	LPPLAYER tTemp = new PLAYER;
	int		iInput(0);

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3 도적) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(tTemp->szName, sizeof(tTemp->szName), "전사");
		tTemp->iAttack = 10;
		tTemp->iHp = 100;
		break;

	case 2:
		strcpy_s(tTemp->szName, sizeof(tTemp->szName), "마법사");
		tTemp->iAttack = 10;
		tTemp->iHp = 100;
		break;

	case 3:
		strcpy_s(tTemp->szName, sizeof(tTemp->szName), "도적");
		tTemp->iAttack = 10;
		tTemp->iHp = 100;
		break;
	}
	//직업선택에 따른 초기화후 해당 힙메모리 포인터 반환
	return tTemp;
}

void RenderPlayer(LPPLAYER lpPlayer)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << lpPlayer->szName << endl;
	cout << "체력 : " << lpPlayer->iHp << "\t공격력 : " << lpPlayer->iAttack << endl;
}

void RenderMonster(LPMONSTER lpMonster)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << lpMonster->szName << endl;
	cout << "체력 : " << lpMonster->iHp << "\t공격력 : " << lpMonster->iAttack << endl;
}

void Field(LPPLAYER lpPlayer)
{
	//입력 값용 변수
	int	iInput(0);

	while (true)
	{
		system("cls");
		RenderPlayer(lpPlayer);

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		if (4 == iInput)
			return;

		//전투 진입 선택시 선택 난이도 따라 몬스터 동적 생성 후 전투 진입
		else if (3 >= iInput)
		{
			LPMONSTER lpMonster =Create_Monster(iInput);
			Fight(lpPlayer,lpMonster);
		}
	}
}

LPMONSTER Create_Monster(int iDifficult)
{
	LPMONSTER tTemp = new MONSTER{};
	const int iBaseHP(30);
	const int iBaseAtk(3);

	switch (iDifficult)
	{
	case EASY:
		strcpy_s(tTemp->szName,sizeof(tTemp->szName),"초급");
		tTemp->iHp = EASY * iBaseHP;
		tTemp->iAttack = EASY * iBaseAtk;
		break;
	case NORMAL:
		strcpy_s(tTemp->szName, sizeof(tTemp->szName), "중급");
		tTemp->iHp = NORMAL * iBaseHP;
		tTemp->iAttack = NORMAL * iBaseAtk;
		break;

	case HARD:
		strcpy_s(tTemp->szName, sizeof(tTemp->szName), "고급");
		tTemp->iHp = HARD * iBaseHP;
		tTemp->iAttack = HARD * iBaseAtk;
		break;
	default:

		break;
	}
	return tTemp;
}

void Fight(LPPLAYER lpPlayer, LPMONSTER lpMonster)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		RenderPlayer(lpPlayer);
		RenderMonster(lpMonster);

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			lpMonster->iHp -= lpPlayer->iAttack;
			lpPlayer->iHp -= lpMonster->iAttack;

			if (0 >= lpPlayer->iHp)
			{
				cout << "플레이어 사망" << endl;
				lpPlayer->iHp = 100;
				system("pause");
				return;
			}
			//몬스터 처리시 몬스터 힙 메모리 반환
			if (0 >= lpMonster->iHp)
			{
				cout << "승리" << endl;
				delete lpMonster;
				lpMonster = nullptr;

				system("pause");
				return;
			}
		}
		// 도망친 경우 몬스터 힙 메모리 반환
		else if (2 == iInput) {
			delete lpMonster;
			lpMonster = nullptr;
			return;
		}
	}

}
