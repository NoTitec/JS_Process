#include <iostream>

using namespace std;

int main()
{
	float		fAver(0.f);

	cout << "평균 값을 입력하세요 : ";
	cin >> fAver;

	if ((0.f > fAver) || (100.f < fAver))
	{
		cout << "잘못된 값입니다" << endl;
	}

	else if ((90.f <= fAver) && (100.f >= fAver))
	{
		cout << "A학점" << endl;
	}

	else if ((80.f <= fAver) && (90.f > fAver))
	{
		cout << "B학점" << endl;
	}

	else if ((70.f <= fAver) && (80.f > fAver))
	{
		cout << "C학점" << endl;
	}

	else if ((60.f <= fAver) && (70.f > fAver))
	{
		cout << "D학점" << endl;
	}
	else
	{
		cout << "F학점" << endl;
	}




	return 0;
}