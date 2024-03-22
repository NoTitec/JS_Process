#include <iostream>
#include <ctime>

using namespace std;

//2. 가위 바위 보 게임 만들기
//
//- 난수를 뽑아서 0~2의 숫자를 만든다.(컴퓨터의 가위 바위 보 값에 해당)
//- 1. 가위 2. 바위 3. 보 4. 종료
//- 사용자가 입력한 값과 난수에 의해 발생한 가위 바위 보를 비교하여 승, 무, 패를 계산
//- 총 5라운드 실행 후, 마지막 라운드 종료 시 몇 승 몇 무 몇 패를 출력
#pragma region 가위 바위 보

//난수 시드 설정 함수
void Set_Random_Number_Seed();
//1~3 난수 뽑는 함수
int Get_Random_Number();
//메뉴출력 함수
void Print_Menu();
//사용자 입력받는 함수
int Get_User_Input();
//컴퓨터 수와 사용자 수 비교하여 승,무,패 판정하는 함수
void Do_Task();

int main()
{
	Set_Random_Number_Seed();

	Do_Task();

	return 0;
}

#pragma endregion 가위 바위 보

void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}

int Get_Random_Number()
{
	return rand() % 3 + 1;
}

void Print_Menu()
{
	cout << "1. 가위 2. 바위 3. 보 4. 종료 : ";
}

int Get_User_Input()
{
	int iInput(0);
	cin >> iInput;
	return iInput;
}

void Do_Task()
{
	int	iComputer(0), iInput(0), iRound(5), iWin(0), iDraw(0), iLose(0);
	bool bChoice(true);

	while ((0 < iRound) && (bChoice))
	{
		system("cls");

		iComputer = Get_Random_Number();
		Print_Menu();

		iInput = Get_User_Input();
		--iRound;

		switch (iInput)
		{
		case 1:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "무승부" << endl;
				++iDraw;
			}
			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "패배" << endl;
				++iLose;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 가위" << endl;
				cout << "승리" << endl;
				++iWin;
			}

			break;

		case 2:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "승리" << endl;
				++iWin;
			}
			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "무승부" << endl;
				++iDraw;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 바위" << endl;
				cout << "패배" << endl;
				++iLose;
			}
			break;

		case 3:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "사용자 : 보" << endl;
				cout << "패배" << endl;
				++iLose;
			}
			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "사용자 : 보" << endl;
				cout << "승리" << endl;
				++iWin;
			}
			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "사용자 : 보" << endl;
				cout << "무승부" << endl;
				++iDraw;
			}
			break;

		case 4:
			bChoice = false;
			cout << "게임을 종료합니다" << endl;
			break;

		default:
			cout << "잘못 누르셨습니다" << endl;
			++iRound;
			break;
		}

		system("pause");
	}

	system("cls");
	cout << "승 : " << iWin << "\t무 : " << iDraw << "\t패 : " << iLose << endl;
	system("pause");
}
