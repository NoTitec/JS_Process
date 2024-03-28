#include <iostream>

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;

char*		Func()
{
	//char	szName[16] = "";
	//cin >> szName;
	//return szName;


	char*	pName = (char*)malloc(16);

	cin >> pName;

	return pName;
}

int	g_iNumber = 200;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//char*	pName = Func();
	//cout << pName << endl;

	
	// 동적 할당 : heap 메모리를 런 타임에 요청하여 사용하게 만드는 문법
	// void* 형 : 주소값이긴 하지만 런타임 시점에 어떤 타입의 주소인지 알지 못할 때 사용, 
	// void*의 사용 시점에는 반드시 명시적인 형 변환을 해줘야 한다.

				// (할당하고자 하는 메모리 크기)
	// void* malloc(size_t _Size)

	//int*	p = (int*)malloc(4);
	//
	//cout << p << endl;		// heap 영역의 주소
	//
	//*p = 10;				// heap 공간에 정수 값 10을 쓰기
	//
	//cout << *p << endl;		// heap 공간에 저장된 값을 읽기

	// (할당하고자 하는 데이터의 개수, 할당하고자 하는 메모리 크기)
	// void*  calloc(size_t _Count,size_t _Size) : 할당할 경우 heap 공간이 자동 0 초기화가 됨

	int*	p = (int*)calloc(3, 4);		  // 동적 배열(heap 메모리에 할당하는 배열)

	 //p[0] = 10;
	 //p[1] = 20;
	 //p[2] = 30;

	//for (int i = 0; i < 5; ++i)
	//	cout << p[i] << endl;

	//cout << "--------------------------------" << endl;

	int*	pMalloc = (int*)malloc(12);		
	
	for (int i = 0; i < 5; ++i)
		cout << pMalloc[i] << endl;


	/*int	iCount(0);
	cin >> iCount;
	int*	ptr = (int*)calloc(iCount, sizeof(int));
	for (int i = 0; i < iCount; ++i)
		cout << ptr[i] << endl;*/

	// void free(void* ptr)	// 메모리 해제 함수(어떤 포인터의 주소)

	//int*	p = (int*)malloc(4);

	//cout << p << endl;

	//free(p);			
	//p = NULL;			// 동적할당한 포인터의 주소 해제 이후에는 반드시 NULL을 채워줄 것

	//cout << "=======================" << endl;
	//cout << p << endl;

	//*p = 10;				// dangling 포인터
	//cout << *p << endl;


#pragma region C++ 동적할당

	//int*	p = new int(50);

	//cout << p << endl;
	//cout << *p << endl;

	//cout << "=======================" << endl;
	
	//delete p;
	//p = nullptr;

	//cout << p << endl;
	//*p = 10;				// dangling 포인터
	//cout << *p << endl;

	/*int*	pArray = new int[3]{10, 20, 30};

	for (int i = 0; i < 3; ++i)
		cout << pArray[i] << endl;*/

	//delete [] pArray;		// 할당한 모든 int형 메모리를 해제(동적 배열 해제)
	
#pragma endregion C++ 동적할당
	
	return 0;
}