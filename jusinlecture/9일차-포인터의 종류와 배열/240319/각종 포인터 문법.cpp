#include <iostream>

using namespace std;

#pragma region ������ ��� ��

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

#pragma endregion ������ ��� ��

#pragma region �������� ����

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

	// ---------------------const �� �������� ����-----------------------

	 //int		iDst(30), iSrc(40);

	 //const int*	p = &iDst;		// �б� ���� ������

	 //int* const	 p = &iDst;		// ��� ������(������ �ϳ��� �ּҸ� ������ ������)

	 //const int* const	 p = &iDst;	// �б� ���� ��� ������


	 //*p = 300;					// �б� ���� �������� ���� ���� ����
	 //p = &iSrc;					// ��� �����͸� ����ϸ� �ٸ� ������ �ּ� ������ �Ұ���������.

	 //cout << p << endl;
	 //cout << *p << endl;

	// ---------------------���� ������--------------------

	int	iTmp(10);

	int* p = &iTmp;

	// p�� �� ����Ʈ? -> 4byte

	cout << "iTmp�� �ּ� �� : " << p << endl;
	cout << "������ p�� ��ǥ �ּ� �� : " << (&p) << endl;

	//���� ������ pp
	int**	pp = &p;

	//p�� �ּ� ���
	cout << &p << endl;
	//pp�� ������ p �� �ּ�
	//p�� �ּҸ� Ÿ�� ���� �ű��ִ°� &iTmp�� ��ǥ�ּ�
	cout << *pp << endl;
	cout << &iTmp << endl;
	//*(&iTmp)�� iTmp�� ��
	cout << **pp << endl;
	cout << iTmp << endl;
		

	return 0;
}


#pragma endregion �������� ����

