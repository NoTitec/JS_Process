#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	 // �޸� �Լ� : �޸� �� �޸� ������ �����ϴ� �Լ���
	// memset, memcpy, memmove, memchr, memcmp

	// memset : �޸� ������ ���ϴ� ���� ����Ʈ ������ ä��� �Լ�
	//	(���� ä����� �ϴ� �޸� ������ ù ��° �ּ�, ä����� �ϴ� ��, �޸� ������ ũ��)
	// void* memset(void*  _Dst, int _Val,size_t _Size)

	//int	iArray[5];

	//memset(iArray, 0, sizeof(iArray));
	//ZeroMemory(iArray, sizeof(iArray));

	//for (size_t i = 0; i < size(iArray); ++i)
	//	cout << iArray[i] << endl;

	// memcpy : �޸� �� �޸� ������ ���縦 �����ϴ� �Լ�
	// memcpy(���� ���� �޸� ������ �ּ�, ������ ������ �޸� ������ �ּ�, ���� ���� �޸� ������ ũ��)

	// memmove : �޸� ���� �ٸ� �޸� ������ �̵� ��, �����ϴ� �Լ�

	int	iArray[5] = { 1, 2, 3, 4, 5 };
	int	iTemp[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	 memcpy(iTemp, iArray, sizeof(iTemp));
	//memmove(iTemp, iArray, sizeof(iTemp));

	for (size_t i = 0; i < size(iTemp); ++i)
		cout << iTemp[i] << endl;

	return 0;
}