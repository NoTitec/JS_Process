#include <iostream>

using namespace std;

int main()
{
	float		fAver(0.f);

	cout << "��� ���� �Է��ϼ��� : ";
	cin >> fAver;

	if ((0.f > fAver) || (100.f < fAver))
	{
		cout << "�߸��� ���Դϴ�" << endl;
	}

	else if ((90.f <= fAver) && (100.f >= fAver))
	{
		cout << "A����" << endl;
	}

	else if ((80.f <= fAver) && (90.f > fAver))
	{
		cout << "B����" << endl;
	}

	else if ((70.f <= fAver) && (80.f > fAver))
	{
		cout << "C����" << endl;
	}

	else if ((60.f <= fAver) && (70.f > fAver))
	{
		cout << "D����" << endl;
	}
	else
	{
		cout << "F����" << endl;
	}




	return 0;
}