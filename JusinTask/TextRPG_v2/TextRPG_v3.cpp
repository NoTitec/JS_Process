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
}PLAYER, * LPPLAYER;
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
    EASY = 1,
    NORMAL,
    HARD
};

//직업선택 후 선택직업 캐릭 생성해서 반환
LPPLAYER Select_Job();
//전사 동적 생성 후 반환
LPPLAYER Make_Warriar();
//마법사 동적 생성 후 반환
LPPLAYER Make_Wizard();
//도적 동적 생성 후 반환
LPPLAYER Make_Bandit();

//함수 포인터 배열
LPPLAYER(*pFunc[3])() = { Make_Warriar,Make_Wizard,Make_Bandit };

void RenderPlayer(LPPLAYER lpplayer);
void RenderMonster(LPMONSTER lpmonster);

//사냥터 함수
void Into_Field(LPPLAYER lpplayer);
//몬스터 생성 함수
LPMONSTER Create_Monster(int iDifficult);
//전투
void Fight(LPPLAYER lpPlayer, LPMONSTER lpMonster);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    LPPLAYER lpPlayer = nullptr;
        //직업 선택하기
    lpPlayer = Select_Job();
        
    while (true)
    {
        int iInput(0);
        system("cls");
        RenderPlayer(lpPlayer);

        cout << "1. 사냥터 2. 종료 : ";
        cin >> iInput;

        if (iInput == 2)
        {
            //종료시 플레이어 메모리 반환 후 종료
            delete lpPlayer;
            lpPlayer = nullptr;
            return 0;
        }
        else
        {
            //사냥터 진입
            Into_Field(lpPlayer);
        }
    }
    
    return 0;
}

LPPLAYER Select_Job()
{
	//플레이어 포인터 변수
	LPPLAYER tTemp;
	int		iInput(0);

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3 도적) : ";
	cin >> iInput;
    tTemp = pFunc[iInput - 1]();
	//직업선택에 따른 생성 후 해당 힙메모리 포인터 tTemp 반환
	return tTemp;
}

LPPLAYER Make_Warriar()
{
	LPPLAYER warriar = new PLAYER;
	strcpy_s(warriar->szName, sizeof(warriar->szName), "전사");
	warriar->iAttack = 10;
	warriar->iHp = 100;

	return warriar;
}

LPPLAYER Make_Wizard()
{
    LPPLAYER wizard = new PLAYER;
    strcpy_s(wizard->szName, sizeof(wizard->szName), "마법사");
    wizard->iAttack = 10;
    wizard->iHp = 100;

    return wizard;
}

LPPLAYER Make_Bandit()
{
    LPPLAYER bandit = new PLAYER;
    strcpy_s(bandit->szName, sizeof(bandit->szName), "도적");
    bandit->iAttack = 10;
    bandit->iHp = 10;

    return bandit;
}

void Into_Field(LPPLAYER lpplayer)
{
    //입력 값용 변수
    int	iInput(0);

    //
    while (true)
    {
        system("cls");
        RenderPlayer(lpplayer);

        cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
        cin >> iInput;

        if (4 == iInput)
            return;

        //전투 진입 선택시 선택 난이도 따라 몬스터 동적 생성 후 전투 진입
        else if (3 >= iInput)
        {
            LPMONSTER lpMonster = Create_Monster(iInput);
            Fight(lpplayer, lpMonster);
        }
    }
}

void RenderPlayer(LPPLAYER lpplayer)
{
    cout << "----------------------------------------" << endl;
    cout << "이름 : " << lpplayer->szName << endl;
    cout << "체력 : " << lpplayer->iHp << "\t공격력 : " << lpplayer->iAttack << endl;
}
void RenderMonster(LPMONSTER lpmonster)
{
    cout << "----------------------------------------" << endl;
    cout << "이름 : " << lpmonster->szName << endl;
    cout << "체력 : " << lpmonster->iHp << "\t공격력 : " << lpmonster->iAttack << endl;
}

LPMONSTER Create_Monster(int iDifficult)
{
    LPMONSTER tTemp = new MONSTER{};
    const int iBaseHP(30);
    const int iBaseAtk(3);

    switch (iDifficult)
    {
    case EASY:
        strcpy_s(tTemp->szName, sizeof(tTemp->szName), "초급");
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