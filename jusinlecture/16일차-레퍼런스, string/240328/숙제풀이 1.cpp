// 240328.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

typedef struct tagInfo
{
	char	szName[32];
	int		iAttack;
	int		iHp;

}INFO;

enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	LOAD,
	END
};

INFO*		Select_Job();
void		Main_Game(INFO* _pPlayer);
void		Create_Obj(INFO** ppInfo, const char* pName, int iAttack, int iHp);
void		Render(INFO* pInfo);
int			Fight(INFO* pPlayer, INFO* pMonster);

bool		Save_Data(INFO* _pPlayer);
bool		Load_Data(INFO** _ppPlayer);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	INFO*	pPlayer = Select_Job();

	if (nullptr == pPlayer)
		return -1;

	Main_Game(pPlayer);

	//if (pPlayer)
	if (nullptr != pPlayer)
	{
		delete pPlayer;
		pPlayer = nullptr;
	}

	return 0;
}

INFO*		Select_Job()
{
	INFO*	pTemp = nullptr;
	int		iInput(0);
	bool	bContinue(false);

	while (!bContinue)
	{
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료) : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			pTemp = new INFO;
			strcpy_s(pTemp->szName, sizeof(pTemp->szName), "전사");
			pTemp->iAttack = 10;
			pTemp->iHp = 100;
			bContinue = true;
			break;

		case WIZARD:
			Create_Obj(&pTemp, "마법사", 10, 100);
			bContinue = true;
			break;

		case THIEF:
			pTemp = new INFO;
			strcpy_s(pTemp->szName, sizeof(pTemp->szName), "도적");
			pTemp->iAttack = 10;
			pTemp->iHp = 100;
			bContinue = true;
			break;

		case LOAD:
			bContinue = Load_Data(&pTemp);
			system("pause");
			break;

		case END:
			cout << "게임을 종료합니다" << endl;
			bContinue = true;
			break;

		default:
			cout << "잘못 입력하셨습니다" << endl;
			break;
		}
	}

	return pTemp;
}
void		Main_Game(INFO* _pPlayer)
{
	int		iInput(0);
	INFO*	pMonster = nullptr;
	bool	bSave = false;

	while (true)
	{
		system("cls");

		Render(_pPlayer);

		cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Obj(&pMonster, "초급", 3, 30);
			break;

		case 2:
			Create_Obj(&pMonster, "중급", 6, 60);
			break;

		case 3:
			Create_Obj(&pMonster, "고급", 9, 90);
			break;

		case 4:
			bSave = Save_Data(_pPlayer);
			system("pause");
			break;

		case 5:
			return;
		}

		if (bSave)
		{
			bSave = false;
			continue;
		}

		int iResult = Fight(_pPlayer, pMonster);

		if (1 == iResult)
		{
			_pPlayer->iHp = 100;
		}

		if (nullptr != pMonster)
		{
			delete pMonster;
			pMonster = nullptr;
		}

	}

}

void		Render(INFO* pInfo)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << pInfo->szName << endl;
	cout << "체력 : " << pInfo->iHp << "\t공격력 : " << pInfo->iAttack << endl;
}
void		Create_Obj(INFO** ppInfo, const char* pName, int iAttack, int iHp)
{
	// int iData(0);
	// 
	// Add(&iData);
	// 
	// void Add(int* p)
	// {
	// 		*p = 10;
	// }

	(*ppInfo) = new INFO;

	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
	(*ppInfo)->iAttack = iAttack;
	(*ppInfo)->iHp = iHp;
}

int		Fight(INFO* pPlayer, INFO* pMonster)
{
	int iInput(0);

	while (true)
	{
		system("cls");

		Render(pPlayer);
		Render(pMonster);

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp -= pMonster->iAttack;

			if (0 >= pPlayer->iHp)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}

			if (0 >= pMonster->iHp)
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
bool		Save_Data(INFO* _pPlayer)
{
	FILE*	pSaveFile = nullptr;

	errno_t		err = fopen_s(&pSaveFile, "../Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(_pPlayer, sizeof(INFO), 1, pSaveFile);
		cout << "저장 성공" << endl;

		fclose(pSaveFile);
		return true;
	}
	else
		cout << "저장 실패" << endl;

	return false;

}
bool		Load_Data(INFO** _ppPlayer)
{
	(*_ppPlayer) = new INFO;

	FILE*	pLoadFile = nullptr;

	errno_t err = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

	if (0 == err)
	{
		fread((*_ppPlayer), sizeof(INFO), 1, pLoadFile);

		cout << "불러오기 성공" << endl;

		fclose(pLoadFile);

		return true;
	}
	else
		cout << "불러오기 실패" << endl;

	return false;
}