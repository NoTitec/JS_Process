//	단일 주석 : 한 줄 안에 있는 글씨를 컴파일 시 제외
/*	복수 주석 : 여러 줄짜리 글씨를 컴파일 시 제외*/

//실행 파일 생성 과정
// 1. 코드 작성 -> 2. 전 처리기 -> 3. 컴파일 -> 4. 어셈블러 -> 5. 링크 -> 6. 실행파일 생성

// 컴파일러의 역할 
// 1. 코드 번역기 2. 실행 파일 생성기

#pragma region hello world

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "Hello world" << endl;
//
//	return 0;
//}

#pragma endregion hello world

#pragma region 변수의 종류

#include <iostream>

using namespace std;

int main()
{
	// 상수: 변하지 않는 숫자

	// 리터럴 상수 : 10, 3.14
	// 심볼릭 상수 : 프로그래밍 언어가 제공하는 어떤 상징적인 기호를 이용하여 상수로 만들어 놓은 상태
	// (ex)	const int iA(10);
	
	// 변수 : 코드의 흐름에 따라 변하는 숫자

	////////////////////////////////////////////////
	// 선언 : 어떤 자료 타입의 어떤 이름을 갖고 있는지 컴파일러에게 알리는 문법
	// 초기화 : 앞선 선언 시점에 메모리 공간에 사용자가 원하는 값으로 채워놓은 상태
	// 재정의 : 같은 공간 안에서 같은 이름을 사용할 수 없음

	// int	iNumber;			// int형 변수 iNumber를 선언하다.
	// int	iNumber = 10;		// int형 변수 iNumber를 선언과 동시에 초기화하다.(c언어 시절의 초기화 방식)
	// int	iNumber(10);			// int형 변수 iNumber를 선언과 동시에 초기화하다.(c++의 초기화 방식)

	// cout << iNumber << endl;

	// 메모리 크기 단위 (byte-> kb -> M -> G -> T)

	// 연산의 최소 단위 : bit
	// 저장의 최소 단위 : byte(1byte == 8bit)

	// 정수 : short(2), int(4), long(4), long long(8)
	// __int16, __int32, __int64

	// unsigned : 양수 값만 저장, 정수 타입의 자료 타입에만 사용 가능

	unsigned short		sName = 32769;		// -32768 ~ 32767
											// 0 ~ 65535
	cout << sName << endl;

	sName = 40000;

	cout << sName << endl;

	short oName = 32768;
	cout << oName<<'\n';
	oName = -32770;
	cout << oName<<'\n';
	//실수
	//문자
	//unsigned char	cName = 65;
	//cout << cName << endl;

	//논리




	return 0;
}

#pragma endregion 변수의 종류


