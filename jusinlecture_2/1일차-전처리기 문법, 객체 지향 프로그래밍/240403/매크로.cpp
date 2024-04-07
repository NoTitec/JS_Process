#include "stdafx.h"

// 매크로 : 지속적인 동작을 기능화 한 것

// 상수 매크로 : 리터럴 상수 값을 문자 형태로 기호화 한 것
// 함수 매크로 : 짧은 형태의 코드를 함수 형식과 비슷하게 만들어 제공하는 것

#define		PI		3.14f				// 단순 치환
#define		MIN_STR	64
#define		MAX_STR	256

// 함수 매크로는 자료형과 상관 없이 동작한다(코드의 단순 치환이기 때문)
// 함수 호출보다 속도가 월등히 빠름

#define		SQUARE(x)	((x) \
* (x))

//////////////////////////////////////////////
#define		STRINGJOB(A, B) #A "의 직업은 " #B "입니다."
//////////////////////////////////////////////
#define		COMBINE(A, B)	A##B

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

int main()
{

	//cout << SQUARE(1.21f) << endl;
	//cout << 1.21f * 1.21f  << endl;
	//cout << SQUARE('a') << endl;

	//cout << SQUARE(2 + 2) << endl;
	//cout << 2 + 2 * 2 + 2 << endl;

	//cout << STRINGJOB(이순신, 장군) << endl;
	//cout << COMBINE(10, 20) << endl;

	int*	p = new int;

	SAFE_DELETE(p);


    return 0;
}

