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
	// 공용체 : 메모리 공간을 공유하여 사용하게 만드는 사용자 정의 자료형

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