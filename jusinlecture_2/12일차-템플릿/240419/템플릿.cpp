#include "stdafx.h"

template<typename T>	// �Լ� ���ø��� ��(���� ���ø�)
T Add(T a, T b)
{
	return a + b;
}
// ���ø� Ư��ȭ	 : Ư�� �ڷ����� ����� �� �ֵ��� ����� ���ø� ���� -> ����ϴ����� int, long ó�� ���ڻ���� ������ �ڷ� ������ �ٸ���쿡 �����ϱ�����
//					���� ���ø��� ���� ������ �ڿ� ���� ����

template<>
char*	Add(char* a, char* b)
{
	int		iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// Ư��ȭ�� ������ ��� �����ε��� �����ϴ�.
template<>
const char*	Add(const char* a, const char* b)
{
	int		iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

template<typename T1, typename T2, typename T3>
T3		Add(T1 a, T2 b)
{
	return a + b;
}

#define SAFE_DELETE(p)		if(p) { delete p; p = nullptr; }

//���ڰ� & �� ���� : T�� ������ ���纻�� �Լ����ο��� ���ǰ� �Լ������ ������⶧���� ������ ���Ѱ� ���⶧��
template<typename T>
void Safe_Delete(T Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

int main()
{
	// ���ø� : ��Ʋ, Ʋ

	// - ����� ���� �Ǿ� ������ �ڷ����� ���� �Ǿ� ���� ���� ����
	// 
	// - �Լ� ���ø� : �Լ��� ����� �� ���ø�	-�ν��Ͻ�ȭ> ���ø� �Լ� : ���ø��� ���� ������ �Լ�
	// - Ŭ���� ���ø� : Ŭ���� ����� �� ���ø�	-�ν��Ͻ�ȭ> ���ø� Ŭ���� : ���ø��� ���� ������ Ŭ����
			
	//cout << Add<int>(10, 20) << endl;			// ���ø� �Լ�
	//cout << Add<long>(10, 20) << endl;
	//cout << Add<float>(1.1f, 2.2f) << endl;

	//char* ptr = Add<char*>("jusin", "_hello");
	//cout << ptr << endl;
	//delete[]ptr;

	//const char* con_ptr = Add<const char*>("jusin", "_hello");
	//cout << con_ptr << endl;
	//delete[]con_ptr;
	
	// double	dNumber = Add<int, float, double>(10, 20.1f);
	// cout << dNumber << endl;


	int*	p = new int;

	Safe_Delete<int*>(p);

	return 0;
}