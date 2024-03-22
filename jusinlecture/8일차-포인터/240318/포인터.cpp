#include <iostream>

using namespace std;

void		Plus(int _iData);
void		Plus(int* _pData);

int main()
{
	
	// 포인터 : 주소값을 참조하여 메모리 공간의 값을 읽거나 쓸 수 있도록 하는 자료형

	// int		iA = 0;
	// int*	p;
	// cout << &iA << endl;
	// cout << *(&iA) << endl;
	// *(&iA) = 10;

	// p = &iA;
	// *p = 10;

	// cout << iA << endl;

	// 포인터는 작성하는 프로그램이 몇 비트 기반이냐에 따라 크기가 결정된다.
	// ex) 32bit -> 포인터의 크기는 4byte
		
	// 32bit -> 4byte
	// 0x0	  -> 0xffffffff	-> 15	-> 1111 -> 4bit * 8개 -> 32bit -> 4byte


	/////////////////////////////////

	// int		iA(0);
	// 
	// int*	p = &iA;
	// 
	// *p = 10;
	// 
	// cout << iA << endl;

	/////////////////////////////////

	//int		iNumber(100);

	//cout << &iNumber << endl;

	//Plus(&iNumber);

	//cout << iNumber << endl;

	
	int		iB(20);

	int*	p2 = &iB;

	cout << p2 << endl;

	//p2 += 1;	// 포인터 연산 : 가리키던 주소 공간을 참조하는 자료형의 크기만큼 이동하여 가리키는 대상을 바꾸는 연산
	p2++;
	
	cout << p2 << endl;

	*p2 = 100;		// dangling 포인터 : 허가 받지 않은 주소 공간에 접근하는 포인터로 읽기 또는 쓰기를 하면 안되는 공간임에도
					// 주소를 갖고 있는 이유만으로 비정상적인 동작을 하는 포인터를 말함

	cout << *p2 << endl;



	return 0;
}
void		Plus(int _iData)
{
	_iData += 100;
}
void		Plus(int* _pData)
{
	cout << _pData << endl;

	// int*		int
	(*_pData) += 100;
}