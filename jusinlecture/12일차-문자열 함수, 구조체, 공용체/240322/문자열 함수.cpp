#include <iostream>

using namespace std;

int main()
{

	// 문자열 복사 함수

	// strcpy(복사 받을 문자열, 복사 할 문자열)
	// char* strcpy(char* _Dest, char const* _Source)
	
	// strcpy_s(복사 받을 문자열, 복사 받을 문자열 메모리 크기, 복사 할 문자열)
	//errno_t strcpy_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source)
	
	/*char	szName[32] = "hellohellohello";
	char	szTemp[32] = "world";

	cout << strcpy_s(szName, sizeof(szName), szTemp) << endl;
	cout << szName << endl;*/

	// 문자열 결합 함수 : 두 문자열을 결합시키는 함수

	// (결합한 최종 결과 문자열, 결합할 문자열)
	//char* strcat( char, _Destination,char const*, _Source)

	// (결과 값을 저장할 문자열, 결과 값을 저장할 문자열의 크기, 결합할 문자열)
	// errno_t __cdecl strcat_s(char* _Destination, rsize_t _SizeInBytes,char const* _Source)
		
	//char	szName[32] = "hello";
	//char	szTemp[32] = "_world";

	//strcat_s(szName, sizeof(szName), szTemp);

	//cout << szName << endl;
	//cout << szTemp << endl;

	// 문자열 길이를 계산해주는 함수(null문자를 제외한 순수한 문자 길이를 계산)
	// size_t strlen(char* pStr)

	// int iLength = strlen("hello");
	// cout << iLength << endl;

	// 두 문자열의 일치 여부를 판단하는 함수
	// (비교할 문자열 주소1, 비교할 문자열 주소2)
	// int strcmp(char const* _Str1, char const* _Str2);

	/*char	szName[32] = "hello";

	if (!strcmp("hello", szName))
		cout << "일치" << endl;

	else
		cout << "불일치" << endl;*/

	return 0;
}