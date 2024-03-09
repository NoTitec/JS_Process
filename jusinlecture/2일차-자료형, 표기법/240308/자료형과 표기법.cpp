#include <iostream>

using namespace std;

int main()
{
#pragma region 실수 타입 자료형

	// float(4), double(8), long double(8)
	// 소수점 이하의 값을 많이 저장할 수록 정밀도가 높다라고 말할 수 있다.

	//float		fTime = 3.14f;		// f는  float 형을 의미하는 상수 기호
	//int		iData = 10;
	//long		lData = 10l;

#pragma endregion 실수 타입 자료형

#pragma region 문자 타입 자료형

	//char(1),			wchar_t(2)
	//아스키코드 표		유니코드 표

	// SBCS(아스키코드만 사용)	->	MBCS(아스키, 유니코드 겸하여 사용) -> WBCS(유니코드로 통일)
	
	// ABCD		-> 4byte
	// ㄱㄴㄷㄹ	-> 8byte
	
	// char		cName = 'A';
	// cName = "Hello world";
	// cout << cName << endl;
	
	// char	cName = 65;
	// cout << cName << endl;
	
#pragma endregion 문자 타입 자료형

#pragma region 논리 타입 자료형

	// bool(1) : 참 또는 거짓을 표현하기 위한 자료형

	// bool		bSelect = true;		// false
	// cout << bSelect << endl;

#pragma endregion 논리 타입 자료형

#pragma region 변수 이름 짓기와 표기법

	// 변수 이름 짓기

 // 1. 변수 이름은 알파벳과 숫자로 구성 할 수 있다.단, 숫자가 맨 앞 글자로 올 수 없음
 // 2. 변수 이름은 대소문자를 확실히 구분한다.
 // 3. 프로그래밍에서 제공하는 키워드로 변수 이름을 지을 수 없다.
 // (ex) int namespace; (x)
 // 4. 변수 이름은 공백 또는 특수 문자가 올 수 없다. 단, _는 허용 (ex) int iPlayer_Hp;
 // 5. 같은 이름의 변수를 같은 공간에서 재 선언(재 정의)할 수 없다.

 // 표기법

 // 1. 헝가리안 표기법 : 변수 이름 앞에 자료형을 의미하는 알파벳을 삽입
 // int iHp, float fAver;
 
 // 2. 카멜 표기법 : 단어와 단어 사이를 대문자를 삽입하여 구분
 // int playerHp;
 
 // 3. 파스칼 표기법 : 변수 이름마다 첫 글자를 대문자로 표기하는 방법
 // int PlayerHp;
 
 // 4. 언더바 표기법 : 단어와 단어 사이에 _를 삽입
 // void	Attack_Monster(int _iAttack);

#pragma endregion 변수 이름 짓기와 표기법

	return 0;
}