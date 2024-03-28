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

	
	// ���� �Ҵ� : heap �޸𸮸� �� Ÿ�ӿ� ��û�Ͽ� ����ϰ� ����� ����
	// void* �� : �ּҰ��̱� ������ ��Ÿ�� ������ � Ÿ���� �ּ����� ���� ���� �� ���, 
	// void*�� ��� �������� �ݵ�� ������� �� ��ȯ�� ����� �Ѵ�.

				// (�Ҵ��ϰ��� �ϴ� �޸� ũ��)
	// void* malloc(size_t _Size)

	//int*	p = (int*)malloc(4);
	//
	//cout << p << endl;		// heap ������ �ּ�
	//
	//*p = 10;				// heap ������ ���� �� 10�� ����
	//
	//cout << *p << endl;		// heap ������ ����� ���� �б�

	// (�Ҵ��ϰ��� �ϴ� �������� ����, �Ҵ��ϰ��� �ϴ� �޸� ũ��)
	// void*  calloc(size_t _Count,size_t _Size) : �Ҵ��� ��� heap ������ �ڵ� 0 �ʱ�ȭ�� ��

	int*	p = (int*)calloc(3, 4);		  // ���� �迭(heap �޸𸮿� �Ҵ��ϴ� �迭)

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

	// void free(void* ptr)	// �޸� ���� �Լ�(� �������� �ּ�)

	//int*	p = (int*)malloc(4);

	//cout << p << endl;

	//free(p);			
	//p = NULL;			// �����Ҵ��� �������� �ּ� ���� ���Ŀ��� �ݵ�� NULL�� ä���� ��

	//cout << "=======================" << endl;
	//cout << p << endl;

	//*p = 10;				// dangling ������
	//cout << *p << endl;


#pragma region C++ �����Ҵ�

	//int*	p = new int(50);

	//cout << p << endl;
	//cout << *p << endl;

	//cout << "=======================" << endl;
	
	//delete p;
	//p = nullptr;

	//cout << p << endl;
	//*p = 10;				// dangling ������
	//cout << *p << endl;

	/*int*	pArray = new int[3]{10, 20, 30};

	for (int i = 0; i < 3; ++i)
		cout << pArray[i] << endl;*/

	//delete [] pArray;		// �Ҵ��� ��� int�� �޸𸮸� ����(���� �迭 ����)
	
#pragma endregion C++ �����Ҵ�
	
	return 0;
}