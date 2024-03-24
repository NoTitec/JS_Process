#include <iostream>

using namespace std;

#include <stdio.h>

#pragma region 기본적인  구조체 개념
//struct tagInfo
//{
//	char	szName[32];			// 구조체 멤버 변수
//	int		iKor;
//	float	fAver;
//};

//int main()
//{



	// 사용자 정의 자료형 : 프로그래머의 필요에 따라 직접 만들어서 사용하는 자료형
	// 자료형의 정체성을 알려주는 키워드를 반드시 삽입해야 함

	// C언어 사용자 정의 자료형 : 구조체(struct), 공용체(union), 열거체(enum)
	// C++  사용자 정의 자료형 : 구조체(struct), 공용체(union), 열거체(enum) + 클래스(class)


	// 구조체 : 여러 데이터 타입을 모아서 하나의 자료형으로 만들어 놓은 데이터의 집합
	// 블록 단위 데이터의 한 예

	//tagInfo		tInfo;		// 구조체 변수 선언*/

	////cout <<		tInfo.iKor << endl;
	////tagInfo		tInfo = {"홍길동", 100, 3.14f };

	//cin >> tInfo.iKor;		// . : 멤버 접근 연산자
	//cout << tInfo.iKor << endl;
	//return 0;
//}

#pragma endregion 기본적인  구조체 개념

#pragma region c언어 구조체와 c++ 구조체의 차이점

 typedef struct tagInfo
{
	int		iA;
	float	fB;

	void	Render()		
	{

	}

}INFO ,*LPINFO;

//using	TEMP = struct tagInfo;

int main()
{
	// 1. c언어 시절의 구조체 선언 시에는 반드시 키워드도 삽입해야 함.
	// //struct tagInfo		tInfo = { 10, 3.14f };
	// 2. c언어 시절의 구조체는 함수를 멤버로 소유 할 수가 없음. 

	INFO		tInfo = { 10, 3.14f };
	INFO*		ptInfo = NULL;
	LPINFO		pInfo = NULL;

	pInfo = &tInfo;
	printf("%d\n", sizeof(pInfo));
	printf("%d\n", tInfo.iA);

	cout << pInfo->iA;
	return 0;
}

#pragma endregion c언어 구조체와 c++ 구조체의 차이점

//struct tagInfo
//{
//	int			iC;// 4
//	char		cA[10];//1 *10		
//	short		sB;	//2	
//	long long	llD; //8	
//};
//
//struct tagTemp
//{	
//	char		cA;		// 1
//	short		sB;		// 2
//	int			iC;		// 4
//
//	tagInfo  tInfo;
//};
//
//int main()
//{
//	cout << sizeof(tagInfo) << endl;
//	//cout << sizeof(tagTemp) << endl;
//
//	tagInfo	tInfo;
//
//	tagInfo*	pInfo = &tInfo;
//
//	cout << &tInfo << endl;
//	cout << &tInfo.iC << endl;
//	cout << &tInfo.cA << endl;
//	cout << &tInfo.sB << endl;
//	cout << &tInfo.llD << endl;
//	// (*pInfo).iC = 100;
//	//pInfo->iC = 100;		// 구조체의 주소로 멤버 변수 또는 함수에 접근을 허용하는 연산자
//
//	//cout << (*pInfo).iC << endl;
//	//cout << pInfo->iC << endl;
//
//	return 0;
//}

// 1. 구조체를 이용하여 성적표 프로그램을 만들어라.

// 1. 입력 2. 출력 3. 검색(이름)
// - 입력 시에는 세 명의 학생의 정보를 입력만 받는다.
// - 출력 시에는 모든 학생의 정보를 출력만 한다.
// - 검색 시에는 이름을 입력하여 이름과 일치한 학생의 성적만 출력

// 2. 텍스트 RPG를 완성해와라.