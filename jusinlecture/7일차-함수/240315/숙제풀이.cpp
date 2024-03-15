#include <iostream>
#include <ctime>

using namespace std;


#pragma region 가위 바위 보

/*
int main()
{
	int	iComputer(0), iInput(0), iRound(5), iWin(0), iDraw(0), iLose(0);
	bool bChoice(true);

	srand(unsigned(time(NULL)));

	while ((0 < iRound) && (bChoice))
	{
		system("cls");

		iComputer = rand() % 3 + 1;

		cout << "1. 가위 2. 바위 3. 보 4. 종료 : ";
		cin >> iInput;
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

	return 0;
}*/

#pragma endregion 가위 바위 보

#pragma region 구구단 만들기

//int main()
//{
//	int	iDan(0), iGob(0);
//
//	cout << "단을 입력하세요 : ";
//	cin >> iDan;
//
//	cout << "곱을 입력하세요 : ";
//	cin >> iGob;
//
//	for (int i = 2; i <= iDan; ++i)
//	{
//		for (int j = 1; j <= iGob; ++j)
//		{
//			cout << i << " * " << j << " = " << i * j << endl;
//		}
//
//		cout << "-----------------------------------" << endl;
//	}
//
//	return 0;
//}

#pragma endregion 구구단 만들기

#pragma region 별찍기

//int main()
//{
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if(i >= j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (i <= j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (4 <= i + j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//	
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (4 >= i + j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	return 0;
//}

#pragma endregion 별찍기