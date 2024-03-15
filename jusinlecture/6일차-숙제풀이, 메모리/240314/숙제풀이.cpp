#include <iostream>
#include <ctime>

using namespace std;

#pragma region 구구단 만들기

//int main()
//{	
//	int	i(2), j(1);
//
//	while (10 > i)
//	{
//		cout << i << " * " << j << " = " << i * j << endl;
//		++j;	
//
//		if (9 < j)
//		{
//			++i;
//			j = 1;
//			cout << "--------------------------------" << endl;
//		}
//	}
//
//	return 0;
//}

#pragma endregion 구구단 만들기

#pragma region 자판기 게임 만들기

//int main()
//{
//	int		iMoney(0), iInput(0), iCoke(100), iCider(200), iFanta(300);
//	bool	bChoice(true);
//
//	cout << "돈을 넣어주세요 : ";
//	cin >> iMoney;
//
//	while (bChoice)
//	{
//		system("cls");
//
//		cout << "잔액 : " << iMoney << endl;
//		cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
//		cin >> iInput;
//
//#pragma region if문 작성 예
//		/*if (1 == iInput)
//		{
//			if (iMoney >= iCoke)
//			{
//				cout << "콜라 구매 완료" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (iMoney >= iCider)
//			{
//				cout << "사이다 구매 완료" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			if (iMoney >= iFanta)
//			{
//				cout << "환타 구매 완료" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//
//		else if (4 == iInput)
//		{
//			cout << "잔액은 " << iMoney << " 원 입니다" << endl;
//			bChoice = false;
//		}
//
//		else
//		{
//			cout << "잘못 누르셨습니다" << endl;
//		}*/
//#pragma endregion if문 작성 예
//
//		switch (iInput)
//		{
//		case 1:
//			if (iMoney >= iCoke)
//			{
//				cout << "콜라 구매 완료" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//			break;
//
//		case 2:
//			if (iMoney >= iCider)
//			{
//				cout << "사이다 구매 완료" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//			break;
//
//		case 3:
//			if (iMoney >= iFanta)
//			{
//				cout << "환타 구매 완료" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//			break;
//
//		case 4:
//			cout << "잔액은 " << iMoney << " 원 입니다" << endl;
//			bChoice = false;
//			break;
//
//		default:
//			cout << "잘못 누르셨습니다" << endl;
//			break;
//		}	
//
//		system("pause");
//	}
//
//	return 0;
//}

#pragma endregion 자판기 게임 만들기

#pragma region 홀짝 게임 만들기

//int main()
//{
//	int		iAnswer(0), iInput(0), iRound(5), iWin(0), iLose(0);
//	bool	bChoice(true);
//
//	srand(unsigned(time(NULL)));
//
//	while ((0 < iRound) && bChoice)
//	{
//		system("cls");
//
//		iAnswer = (rand() % 10) + 1;
//
//		cout << "정답 : " << iAnswer << endl;
//
//		cout << iRound << " 회 남았습니다" << endl;
//		cout << "1. 홀수 2. 짝수 3. 종료 : ";
//		cin >> iInput;
//		--iRound;
//
//		if (1 == iInput)
//		{
//			if (0 != iAnswer % 2)
//			{
//				cout << "컴퓨터 : 홀" << endl;
//				cout << "사용자 : 홀" << endl;
//				cout << "정답" << endl;
//				++iWin;
//			}
//			else
//			{
//				cout << "컴퓨터 : 짝" << endl;
//				cout << "사용자 : 홀" << endl;
//				cout << "오답" << endl;
//				++iLose;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (0 != iAnswer % 2)
//			{
//				cout << "컴퓨터 : 홀" << endl;
//				cout << "사용자 : 짝" << endl;
//				cout << "오답" << endl;
//				++iLose;
//			}
//			else
//			{
//				cout << "컴퓨터 : 짝" << endl;
//				cout << "사용자 : 짝" << endl;
//				cout << "정답" << endl;
//				++iWin;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			cout << "게임을 종료합니다" << endl;
//			bChoice = false;
//		}
//		else
//		{
//			cout << "잘못 입력하셨습니다" << endl;
//			++iRound;
//		}
//
//		system("pause");
//	}
//
//	system("cls");
//	cout << "승 : " << iWin << "\t패 : " << iLose << endl;
//	system("pause");
//
//	return 0;
//}

#pragma endregion 홀짝 게임 만들기



//1. 2중 for문을 이용하여 구구단 2~9단까지 출력하기
//
//- 단과 곱을 입력 받아라.
//
//ex) 5단, 4곱
//
//2 * 1 = 2
//2 * 2 = 4
//2 * 3 = 6
//2 * 4 = 8
//
//3 * 1 = 2
//3 * 2 = 4
//3 * 3 = 6
//3 * 4 = 8
//
//4 * 1 = 2
//4 * 2 = 4
//4 * 3 = 6
//4 * 4 = 8
//
//5 * 1 = 2
//5 * 2 = 4
//5 * 3 = 6
//5 * 4 = 8
//
//2. 가위 바위 보 게임 만들기
//
//- 난수를 뽑아서 0~2의 숫자를 만든다.(컴퓨터의 가위 바위 보 값에 해당)
//- 1. 가위 2. 바위 3. 보 4. 종료
//- 사용자가 입력한 값과 난수에 의해 발생한 가위 바위 보를 비교하여 승, 무, 패를 계산
//- 총 5라운드 실행 후, 마지막 라운드 종료 시 몇 승 몇 무 몇 패를 출력

/*
3. 2중 for문을 이용한 별찍기

*
**
***
****
*****

*****
 ****
  ***
   **
    *

	* 
   ** 
  ***
 ****
*****

*****
****
***
**
*

*/