#include "stdafx.h"

// ��ũ�� : �������� ������ ���ȭ �� ��

// ��� ��ũ�� : ���ͷ� ��� ���� ���� ���·� ��ȣȭ �� ��
// �Լ� ��ũ�� : ª�� ������ �ڵ带 �Լ� ���İ� ����ϰ� ����� �����ϴ� ��

#define		PI		3.14f				// �ܼ� ġȯ
#define		MIN_STR	64
#define		MAX_STR	256

// �Լ� ��ũ�δ� �ڷ����� ��� ���� �����Ѵ�(�ڵ��� �ܼ� ġȯ�̱� ����)
// �Լ� ȣ�⺸�� �ӵ��� ������ ����

#define		SQUARE(x)	((x) \
* (x))

//////////////////////////////////////////////
#define		STRINGJOB(A, B) #A "�� ������ " #B "�Դϴ�."
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

	//cout << STRINGJOB(�̼���, �屺) << endl;
	//cout << COMBINE(10, 20) << endl;

	int*	p = new int;

	SAFE_DELETE(p);


    return 0;
}

