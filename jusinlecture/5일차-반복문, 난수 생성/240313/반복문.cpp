#include <iostream>
// #include <time.h>
#include <ctime>

using namespace std;

// 모던 c++ 이후에 등장한 typedef 대체 문법
using BOOL = int;

int main()
{

#pragma region while

	//int		iNumber(3);

	//while (--iNumber)
	//{
	//	cout << 1 << endl;
	//}



	/*while (true)
	{
		cout << 1 << endl;
		iNumber--;

		if (0 == iNumber)
		{
			break;
		}
	}*/
	
	/*int i(1);

	while (10 > i)
	{
		cout <<	2 << " * " << i << " = " << i * 2 << endl;
		++i;
	}*/

#pragma endregion while

#pragma region do while

	/*do 
	{
		코드 블럭

	} while (조건식);*/

	/*int		iNumber(3);

	do 
	{
		cout << 1 << endl;

	} while (--iNumber);*/

	//int		iInput(0), iSum(0);

	//do 
	//{
	//	//iInput 입력
	//	cin >> iInput;

	//	//2로 나눈 나머지가 0이 아니면
	//	if (0 != iInput % 2)
	//	{
	//		//continue
	//		continue;			// 반복문 안에서만 사용 가능, 코드의 흐름을 반복문의 맨 끝으로 이동
	//	}
	//	//나머지가 0이면 isum에 입력값이 iInput값 누적합
	//	iSum += iInput;
	//	
	//} //iInput이 -1이 아닌이상 무한반복
	//while (-1 != iInput);

	//cout << "합계 : " << iSum << endl;

#pragma endregion do while

#pragma region for

	//for ( 초기화식 ; 조건식 ; 증감식 )
	//{
	//	코드 블럭
	//}

	// c언어 시절의 for문
	/*int	i = 999;

	for (i = 0; i < 3; i++)
	{
	cout << i << endl;
	}

	cout << i << endl;*/

	// c++이후의 for문

	/*int	i = 999;

	for (int i = 0; i < 3; ++i)
	{
	cout << i << endl;
	}

	cout << i << endl;*/


	/*for (int i = 0, j = 0; i < 3 && j < 3; ++i, j += 2)
	{
	cout << i << endl;
	}*/

#pragma endregion for

#pragma region 이중 for문

//for (int i = 0; i < 2; ++i)
//{
//	cout << 1 << endl;
//
//	for (int j = 0; j < 3; ++j)
//	{
//		cout << 2 << endl;
//	}
//
//	cout << 3 << endl;
//}

#pragma endregion 이중 for문

#pragma region 난수

	// 난수 : 순서나 규칙이 없는 무작위 수

	// rand 함수 : 0 ~ 32767 범위 사이에 있는 무작위의 수를 추출
	// srand함수 : 난수표를 변경해주는 함수
	// time함수 : 현재 시간을 초 단위로 변환하여 불러오는 함수

	//time_t	Time_Dst = 0;
	//// typedef : 기존에 존재하는 자료형을 사용자가 원하는 이름의 자료형으로 대체 또는 추가하여 만드는 문법
	//
	//time(&Time_Dst);

	//cout << Time_Dst << endl;
	
	//시드값 변경
	//srand(time(&Time_Dst));

	// //NULL = 숫자 0

	//srand(unsigned(time(NULL)));

	//cout << rand() << endl;
	//cout << rand() << endl;
	//cout << rand() << endl;

	// well512 난수 발생 알고리즘

	//int		iInput(0);

	//while (true)
	//{
	//	//현재 콘솔창 내용 지우기
	//	system("cls");
	//	
	//	cout << "숫자를 입력하세요 : ";
	//	cin >> iInput;

	//	cout << iInput << endl;
	//	//키를 누를대까지 프로그램을 일시정지
	//	system("pause");
	//}
#pragma endregion 난수

return 0;
}

// 1. while문을 이용하여 구구단 2~9단까지 모두 출력하기

// 2. 자판기 게임
/*
- 소지금을 입력받고 항상 잔액을 출력한다
- 메뉴는 1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 
- 해당 목록을 선택하여 구매 시, "xx 구매 완료"를 출력
- 단, 소지금이 부족할 경우 잔액이 부족합니다 출력
- 4번을 누르면 "거스름 돈은 <잔액>입니다" 출력 후, 프로그램 종료
*/

// 3. 홀짝 게임

//- 매 라운드마다 난수를 이용하여 무작위 수를 도출, 화면에 출력하라
//- 난수의 범위는 1~10 사이 중 하나를 반복할 때마다 발생
//- 1. 홀수 2. 짝수 3. 종료
//- 총 5라운드를 실시하고 마지막 라운드로 끝나면 '몇 승 몇 패' 출력