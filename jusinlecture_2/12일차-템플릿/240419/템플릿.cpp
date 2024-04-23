#include "stdafx.h"

template<typename T>	// 함수 템플릿의 예(단항 템플릿)
T Add(T a, T b)
{
	return a + b;
}
// 템플릿 특수화	 : 특정 자료형만 사용할 수 있도록 만드는 템플릿 문법 -> 사용하는이유 int, long 처럼 인자생긴것 같지만 자료 구조는 다른경우에 대응하기위해
//					원본 템플릿이 먼저 생성된 뒤에 적용 가능

template<>
char*	Add(char* a, char* b)
{
	int		iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// 특수화를 진행한 경우 오버로딩도 가능하다.
template<>
const char*	Add(const char* a, const char* b)
{
	int		iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

template<typename T1, typename T2, typename T3>
T3		Add(T1 a, T2 b)
{
	return a + b;
}

#define SAFE_DELETE(p)		if(p) { delete p; p = nullptr; }

//인자가 & 인 이유 : T로 받으면 복사본이 함수내부에서 사용되고 함수종료시 사라지기때문에 원본은 변한게 없기때문
template<typename T>
void Safe_Delete(T Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

int main()
{
	// 템플릿 : 형틀, 틀

	// - 기능은 결정 되어 있지만 자료형은 결정 되어 있지 않은 상태
	// 
	// - 함수 템플릿 : 함수의 모양을 띈 템플릿	-인스턴스화> 템플릿 함수 : 템플릿에 의해 생성된 함수
	// - 클래스 템플릿 : 클래스 모양을 띈 템플릿	-인스턴스화> 템플릿 클래스 : 템플릿에 의해 생성된 클래스
			
	//cout << Add<int>(10, 20) << endl;			// 템플릿 함수
	//cout << Add<long>(10, 20) << endl;
	//cout << Add<float>(1.1f, 2.2f) << endl;

	//char* ptr = Add<char*>("jusin", "_hello");
	//cout << ptr << endl;
	//delete[]ptr;

	//const char* con_ptr = Add<const char*>("jusin", "_hello");
	//cout << con_ptr << endl;
	//delete[]con_ptr;
	
	// double	dNumber = Add<int, float, double>(10, 20.1f);
	// cout << dNumber << endl;


	int*	p = new int;

	Safe_Delete<int*>(p);

	return 0;
}