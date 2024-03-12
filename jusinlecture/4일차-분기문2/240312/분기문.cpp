#include <iostream>

using namespace std;

#pragma region 예외 사항
//int main()
//{
//	// 디버깅 단축키
//
//	// Ctrl + . :	선언 / 정의부로 조그만한 화면 띄워줌
//	// F5	: 디버깅 시작
//	// Shfit + F5 : 디버깅 중지
//	// F9	: 중단점 삽입
//	// F11	: 한 단계씩 코드 실행(중간에 함수가 있으면 거기에 들어감)
//	// F10	: 프로시저 단위 실행(현재 코드 내에서, 한줄씩 실행)
//	// Ctrl + shift + f9 : 모든 디버깅 포인트 삭제
//
//	int		iData(0);
//
//	if (1)
//	{
//	cout << 1 << endl;
//	iData = 1;
//	}
//	else if (1)
//	{
//	cout << 2 << endl;
//	iData = 2;
//	}
//
//	else if (1)
//	{
//	cout << 3 << endl;
//	iData = 3;
//	}
//
//	else
//	{
//	cout << 4 << endl;
//	iData = 4;
//	}
//
//	cout << iData <<"end"<< endl;
//
//
//	int		iData2(0);
//
//	if (1)
//	{
//		cout << 1 << endl;
//		iData2 = 1;
//	}
//
//	if (1)
//	{
//		cout << 2 << endl;
//		iData2 = 2;
//	}
//
//	if (1)
//	{
//		cout << 3 << endl;
//		iData2 = 3;
//	}
//
//	else
//	{
//		cout << 4 << endl;
//		iData2 = 4;
//	}
//
//	cout << iData2 << endl;
//
//	 int		iA(10), iB(20);
//	 
//	 if ((iA < iB) && (iA = 999))
//	 {
//	 	cout << iA << endl;			// 단일 코드 시에는 중괄호 표기를 생략 할 수 있다.
//	 }
//			
//
//	return 0;
//}
#pragma endregion 예외 사항

#pragma region switch

int main()
{
	// switch 문(상수 조건 분기문) : 상수(정수)만 취급하며 실수로는 분기를 할 수 없음, 정수의 조건에 따라 코드의 흐름을 나눔
	
	int iInput(0);

	const int iNumber(1);		// 심볼릭 상수여도 case에 적용하는데 문제가 없다.

	cout << "1. 콜라 2. 사이다 3. 환타 : ";
	cin >> iInput;
	
	switch (iInput)
	{
	case 1:						// case 옆에 오는 정수는 반드시 상수여야 한다.
	{
		cout << "콜라" << endl;
		int		iDst(0);
		iDst = 1;
		cout << iDst << endl;
	}
		break;						// 현재 코드의 흐름(블럭)을 탈출시키는 키워드
	case 2 :
		cout << "사이다" << endl;
		//iDst = 2;
		//cout << iDst << endl;
		break;

	case 3 :
		cout << "환타" << endl;
		//iDst = 3;
		//cout << iDst << endl;
		//break;

	default:
		cout << "잘못된 값입니다" << endl;
		break;
	}

	return 0;
}

#pragma endregion switch

#pragma region 삼항 연산자

//int main()
//{
	// 삼항 연산자 : 피연산자가 세 개인 연산자
	// 최대 값 또는 최소 값을 구할 때 유용하게 쓰임
	// 가독성이 떨어짐, 긴 코드를 작성하기에 무리가 있음.

	// (조건식) ? (참일 때 실행하는 코드) : (거짓일 때 실행하는 코드)

	//int		iNumber1(10), iNumber2(20), iMax(0);

	//iMax = (iNumber1 > iNumber2) ? iNumber1 : iNumber2;

	//cout << iMax << endl;

	//return 0;
//}

#pragma endregion 삼항 연산자