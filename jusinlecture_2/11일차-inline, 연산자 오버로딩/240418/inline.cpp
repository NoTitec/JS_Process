// 240418.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define		SQUARE(X)	X * X

inline int		Square(int x)
{
	return x * x;
}

int main()
{
	// inline �Լ� ���� : �ڵ带 ���� �����ϱ� ������ �Ϲ� �Լ� ȣ�� �ӵ� ���� ����
	// inline �Լ� ���� : ��ũ�ο� ���Ͽ� �ڷ����� �������� �ڵ�, ���� �ڵ带 �����ϰ� �Ǹ� ���� ������ ũ�Ⱑ ���ȭ
	
	// cout << SQUARE(5) << endl;
	// cout << SQUARE(3.14) << endl;
	
	// cout << Square(5) << endl;
	// cout << Square(3.14) << endl;

	// inline �Լ��� �Ϲ� �Լ��� �ڵ����� ��ȯ�Ǵ� ��

	// 1. �Լ� �����Ϳ� �ζ��� �Լ��� �̸��� ���� �� ��
	// 2. �ζ��� �Լ��� ��� ���·� ȣ�� �� ��

    return 0;
}


