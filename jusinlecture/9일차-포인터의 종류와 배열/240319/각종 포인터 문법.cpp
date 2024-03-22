#include <iostream>

using namespace std;

#pragma region 포인터 사용 예

//void	Swap(int _iA, int _iB);
//void	Swap(int* _pA, int* _pB);
//
//int main()
//{
//	int		iA(10), iB(20);
//
//	cout << iA << "\t" << iB << endl;
//
//	Swap(&iA, &iB);
//
//	cout << iA << "\t" << iB << endl;
//
//	return 0;
//}
//void	Swap(int _iA, int _iB)
//{
//	int iC(0);
//
//	 iC = _iA;
//	_iA = _iB;
//	_iB = iC;
//}
//void	Swap(int* _pA, int* _pB)
//{
//	int iC(0);
//
//	  iC = *_pA;
//	*_pA = *_pB;
//	*_pB = iC;
//}

#pragma endregion 포인터 사용 예

#pragma region 포인터의 종류

int	main()
{
	/*int		iA(0);

	int*	p = &iA;

	*p = 10;

	cout << p << endl;
	cout << iA << endl;
	cout << "-----------------" << endl;

	int		iB(100);

	p = &iB;

	*p = 200;

	cout << p << endl;
	cout << iA << endl;
	cout << iB << endl;*/

	// ---------------------const 와 포인터의 관계-----------------------

	 //int		iDst(30), iSrc(40);

	 //const int*	p = &iDst;		// 읽기 전용 포인터

	 //int* const	 p = &iDst;		// 상수 포인터(오로지 하나의 주소만 참조가 가능함)

	 //const int* const	 p = &iDst;	// 읽기 전용 상수 포인터


	 //*p = 300;					// 읽기 전용 포인터일 때는 쓰기 금지
	 //p = &iSrc;					// 상수 포인터를 사용하면 다른 변수의 주소 참조가 불가능해진다.

	 //cout << p << endl;
	 //cout << *p << endl;

	// ---------------------이중 포인터--------------------

	int	iTmp(10);

	int* p = &iTmp;

	// p는 몇 바이트? -> 4byte

	cout << "iTmp의 주소 값 : " << p << endl;
	cout << "포인터 p의 대표 주소 값 : " << (&p) << endl;

	//이중 포인터 pp
	int**	pp = &p;

	//p의 주소 출력
	cout << &p << endl;
	//pp가 가진건 p 의 주소
	//p의 주소를 타고 가면 거기있는건 &iTmp의 대표주소
	cout << *pp << endl;
	cout << &iTmp << endl;
	//*(&iTmp)는 iTmp의 값
	cout << **pp << endl;
	cout << iTmp << endl;
		

	return 0;
}


#pragma endregion 포인터의 종류

