#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	 // 메모리 함수 : 메모리 대 메모리 단위로 동작하는 함수들
	// memset, memcpy, memmove, memchr, memcmp

	// memset : 메모리 공간에 원하는 값을 바이트 단위로 채우는 함수
	//	(값을 채우고자 하는 메모리 공간의 첫 번째 주소, 채우고자 하는 값, 메모리 공간의 크기)
	// void* memset(void*  _Dst, int _Val,size_t _Size)

	//int	iArray[5];

	//memset(iArray, 0, sizeof(iArray));
	//ZeroMemory(iArray, sizeof(iArray));

	//for (size_t i = 0; i < size(iArray); ++i)
	//	cout << iArray[i] << endl;

	// memcpy : 메모리 대 메모리 단위로 복사를 수행하는 함수
	// memcpy(복사 받을 메모리 공간의 주소, 복사할 데이터 메모리 공간의 주소, 복사 받을 메모리 공간의 크기)

	// memmove : 메모리 값을 다른 메모리 공간에 이동 후, 복사하는 함수

	int	iArray[5] = { 1, 2, 3, 4, 5 };
	int	iTemp[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	 memcpy(iTemp, iArray, sizeof(iTemp));
	//memmove(iTemp, iArray, sizeof(iTemp));

	for (size_t i = 0; i < size(iTemp); ++i)
		cout << iTemp[i] << endl;

	return 0;
}