// 240418.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define		SQUARE(X)	X * X

inline int		Square(int x)
{
	return x * x;
}

int main()
{
	// inline 함수 장점 : 코드를 직접 삽입하기 때문에 일반 함수 호출 속도 보다 빠름
	// inline 함수 단점 : 매크로와 비교하여 자료형에 의존적인 코드, 자주 코드를 삽입하게 되면 실행 파일의 크기가 비대화
	
	// cout << SQUARE(5) << endl;
	// cout << SQUARE(3.14) << endl;
	
	// cout << Square(5) << endl;
	// cout << Square(3.14) << endl;

	// inline 함수가 일반 함수로 자동으로 전환되는 예

	// 1. 함수 포인터에 인라인 함수의 이름을 삽입 할 때
	// 2. 인라인 함수를 재귀 형태로 호출 할 때

    return 0;
}


