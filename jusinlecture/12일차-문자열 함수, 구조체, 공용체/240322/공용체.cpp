#include <iostream>
#include <windows.h>

using namespace std;

struct tagInfo
{
	int		iA;
	float	fB;
};

union uniInfo
{
	int		iA;
	float	fB;
};

int main()
{
	// ����ü : �޸� ������ �����Ͽ� ����ϰ� ����� ����� ���� �ڷ���

	/*tagInfo	tInfo = { 10, 3.14f };

	cout << sizeof(tagInfo) << endl;

	cout << tInfo.iA << endl;
	cout << tInfo.fB << endl;*/


	uniInfo	tInfo = { 3.14f };

	cout << sizeof(uniInfo) << endl;

	cout << tInfo.iA << endl;
	cout << tInfo.fB << endl;

	return 0;
}