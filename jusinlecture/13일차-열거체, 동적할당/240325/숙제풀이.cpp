#include <iostream>

using namespace std;

#pragma region 성적표 만들기

////학생 정보 구조체 정의
//typedef struct tagInfo
//{
//	char szName[32];
//	int	 iKor;
//	int  iEng;
//	int  iMath;
//	int  iTotal;
//	float fAver;
//
//}INFO;
//
//// 배열 포인터, 배열 원소 수
//void	Input_Data(INFO _tStudent[], int _iCount);
//void	Output_Data(INFO _tStudent[], int _iCount);
//void	Search_Data(INFO _tStudent[], int _iCount);
//
//int main()
//{
//	//학생 3명 정보 저장할 학생 구조체 배열
//	INFO	tStudent[3] = {};
//	int iInput(0);
//
//	while (true)
//	{
//		system("cls");
//
//		cout << "1. 입력 2. 출력 3. 검색 4. 종료 : ";
//		cin >> iInput;
//
//#pragma region 생략
//		/*switch (iInput)
//		{
//		case 1:
//			Input_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 2:
//			Output_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 3:
//			Search_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 4:
//			return 0;
//		}*/
//#pragma endregion 생략
//
//		//함수 포인터 배열
//		void(*pFunc[3])(INFO*, int) = { Input_Data, Output_Data, Search_Data };
//
//		if (4 == iInput)
//			return 0 ;
//
//		pFunc[iInput - 1](tStudent, 3);		
//
//		system("pause");
//	}
//	
//	return 0;
//}
//
//void	Input_Data(INFO _tStudent[], int _iCount)
//{
//	for (int i = 0; i < _iCount; ++i)
//	{
//		cout << "이름 입력 : ";
//		cin >> _tStudent[i].szName;
//
//		cout << "국어 입력 : ";
//		cin >> _tStudent[i].iKor;
//		
//		cout << "영어 입력 : ";
//		cin >> _tStudent[i].iEng;
//
//		cout << "수학 입력 : ";
//		cin >> _tStudent[i].iMath;
//
//		_tStudent[i].iTotal = _tStudent[i].iKor + _tStudent[i].iEng + _tStudent[i].iMath;
//		_tStudent[i].fAver = _tStudent[i].iTotal / 3.f;
//	}
//}
//
//void Output_Data(INFO _tStudent[], int _iCount)
//{
//	for (int i = 0; i < _iCount; ++i)
//	{
//		cout << "--------------------------------" << endl;
//		cout << "이름 : " << _tStudent[i].szName << endl;
//		cout << "국어 : " << _tStudent[i].iKor << endl;
//		cout << "영어 : " << _tStudent[i].iEng << endl;
//		cout << "수학 : " << _tStudent[i].iMath << endl;
//		cout << "총점 : " << _tStudent[i].iTotal << endl;
//		cout << "평균 : " << _tStudent[i].fAver << endl;
//	}
//}
//
//void Search_Data(INFO _tStudent[], int _iCount)
//{
//	char	szFindName[32] = "";
//
//	cout << "이름을 입력하세요 : ";
//	cin >> szFindName;
//
//	for (int i = 0; i < _iCount; ++i)
//	{
//		if (!strcmp(szFindName, _tStudent[i].szName))
//		{
//			cout << "--------------------------------" << endl;
//			cout << "이름 : " << _tStudent[i].szName << endl;
//			cout << "국어 : " << _tStudent[i].iKor << endl;
//			cout << "영어 : " << _tStudent[i].iEng << endl;
//			cout << "수학 : " << _tStudent[i].iMath << endl;
//			cout << "총점 : " << _tStudent[i].iTotal << endl;
//			cout << "평균 : " << _tStudent[i].fAver << endl;
//			system("pause");
//			return;
//		}
//	}
//
//	cout << "검색된 이름이 없습니다. 이름은 다음과 같습니다" << endl;
//
//	for (int i = 0; i < _iCount; ++i)
//		cout << "이름 : " << _tStudent[i].szName << endl;
//}

#pragma endregion 성적표 만들기

#pragma region TextRPG

//구조체 정의
typedef struct tagInfo
{
	char	szName[32];
	int		iAttack;
	int		iHp;

}INFO;

//선택한 직업의 플레이어 인스턴스 생성함수
INFO		Select_Job();
//구조체 정보 출력 함수
void		Render(INFO* pInfo);
//사냥터 초기화
void		Field(INFO* pPlayer);
//몬스터 생성
void		Create_Monster(INFO tMonster[], int iCount);
//전투
void		Fight(INFO* pPlayer, INFO* pMonster);

int main()
{
	INFO	tPlayer = {};

	tPlayer = Select_Job();

	int		iInput(0);

	while (true)
	{
		system("cls");
		Render(&tPlayer);

		cout << "1. 사냥터 2. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field(&tPlayer);
			break;

		case 2:
			return 0;
		}
	}

	return 0;
}

INFO		Select_Job()
{
	INFO	tTemp = {};
	int		iInput(0);

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3 도적) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "전사");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;

	case 2:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "마법사");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;

	case 3:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "도적");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;
	}

	return tTemp;
}

void		Render(INFO* pInfo)
{
	cout << "----------------------------------------" << endl;
	cout << "이름 : " << pInfo->szName << endl;
	cout << "체력 : " << pInfo->iHp << "\t공격력 : " << pInfo->iAttack << endl;
}

void		Field(INFO* pPlayer)
{
	int			iInput(0);
	//사냥터서 몬스터 정보들 가진 배열
	INFO		tMonster[3];

	while (true)
	{
		system("cls");
		Render(pPlayer);

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		if (4 == iInput)
			return;

		//int		iArray[3];
		//sizeof(iArray)	-> 12byte		/ 4byte ->	3
		// iArray == &iArray[0]

		else if (3 >= iInput)
		{
			Create_Monster(tMonster, sizeof(tMonster) / sizeof(INFO));
			Fight(pPlayer, &tMonster[iInput- 1]);
		}
	}
}

void		Create_Monster(INFO tMonster[], int iCount)
{
	strcpy_s(tMonster[0].szName, sizeof(tMonster[0].szName), "초급");
	strcpy_s(tMonster[1].szName, sizeof(tMonster[1].szName), "중급");
	strcpy_s(tMonster[2].szName, sizeof(tMonster[2].szName), "고급");

	for (int i = 0; i < iCount; ++i)
	{
		tMonster[i].iHp = (i + 1) * 30;
		tMonster[i].iAttack = (i + 1) * 3;
	}
}
void		Fight(INFO* pPlayer, INFO* pMonster)
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
				pPlayer->iHp = 100;
				system("pause");
				return;
			}

			if (0 >= pMonster->iHp)
			{
				cout << "승리" << endl;
				system("pause");
				return;
			}
		}

		else if (2 == iInput)
			return;
	}

}

#pragma endregion TextRPG

