#include <iostream>

using namespace std;

void		Plus(int _iData);
void		Plus(int* _pData);

int main()
{
	
	// ������ : �ּҰ��� �����Ͽ� �޸� ������ ���� �аų� �� �� �ֵ��� �ϴ� �ڷ���

	// int		iA = 0;
	// int*	p;
	// cout << &iA << endl;
	// cout << *(&iA) << endl;
	// *(&iA) = 10;

	// p = &iA;
	// *p = 10;

	// cout << iA << endl;

	// �����ʹ� �ۼ��ϴ� ���α׷��� �� ��Ʈ ����̳Ŀ� ���� ũ�Ⱑ �����ȴ�.
	// ex) 32bit -> �������� ũ��� 4byte
		
	// 32bit -> 4byte
	// 0x0	  -> 0xffffffff	-> 15	-> 1111 -> 4bit * 8�� -> 32bit -> 4byte


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

	//p2 += 1;	// ������ ���� : ����Ű�� �ּ� ������ �����ϴ� �ڷ����� ũ�⸸ŭ �̵��Ͽ� ����Ű�� ����� �ٲٴ� ����
	p2++;
	
	cout << p2 << endl;

	*p2 = 100;		// dangling ������ : �㰡 ���� ���� �ּ� ������ �����ϴ� �����ͷ� �б� �Ǵ� ���⸦ �ϸ� �ȵǴ� �����ӿ���
					// �ּҸ� ���� �ִ� ���������� ���������� ������ �ϴ� �����͸� ����

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