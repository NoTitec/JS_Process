// JusinTask_Pointer_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <ctime>

using namespace std;


#pragma region 가위 바위 보

//포인터로 DOTASK 수행
void Do_Task(bool* bChoice, int* iComputer, int* iInput, int* iRound, int* iWin, int* iDraw, int* iLose);
int main()
{
	int	iComputer(0), iInput(0), iRound(5), iWin(0), iDraw(0), iLose(0);
	bool bChoice(true);

	//NULL 도 되지만 c++ 문법은 nullptr, 단 C 기반 라이브러리 함수는 NULL을 넘겨주어야 하는경우 있으므로 알고는 있어야함
	int* pComputer(nullptr), * pInput(nullptr), * pRound(nullptr);
	bool* pChoice(nullptr);
	srand(unsigned(time(NULL)));
	pComputer = &iComputer;
	pInput = &iInput;
	pRound = &iRound;

	pChoice = &bChoice;
	Do_Task(pChoice,pComputer,pInput,pRound,&iWin,&iDraw,&iLose);

	system("cls");
	cout << "승 : " << iWin << "\t무 : " << iDraw << "\t패 : " << iLose << endl;
	system("pause");

	return 0;
}

#pragma endregion 가위 바위 보// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

void Do_Task(bool* bChoice, int* iComputer, int* iInput, int* iRound, int* iWin, int* iDraw, int* iLose)
{
	while ((0 < *iRound) && (*bChoice))
	{
		system("cls");

		*iComputer = rand() % 3 + 1;

		cout << "1. 가위 2. 바위 3. 보 4. 종료 : ";
		cin >> *iInput;
		--*iRound;

		switch (*iInput)
		{
		case 1:
			if (1 == *iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "무승부" << endl;
				++*iDraw;
			}
			else if (2 == *iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "패배" << endl;
				++*iLose;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "승리" << endl;
				++*iWin;
			}

			break;

		case 2:
			if (1 == *iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "승리" << endl;
				++*iWin;
			}
			else if (2 == *iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "무승부" << endl;
				++*iDraw;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "패배" << endl;
				++*iLose;
			}
			break;

		case 3:
			if (1 == *iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 보" << endl;
				cout << "패배" << endl;
				++*iLose;
			}
			else if (2 == *iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 보" << endl;
				cout << "승리" << endl;
				++*iWin;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 보" << endl;
				cout << "무승부" << endl;
				++*iDraw;
			}
			break;

		case 4:
			*bChoice = false;
			cout << "게임을 종료합니다" << endl;
			break;

		default:
			cout << "잘못 누르셨습니다" << endl;
			++*iRound;
			break;
		}

		system("pause");
	}
}
