#include <iostream>

using namespace std;

#pragma region ����ü

enum	NUMBER
{
	ONE = 1, 
	TWO,
	THREE,
	FOUR,
	FIVE,
	END
};

int main()
{
	 const int iArray[5] = { 1, 2, 3 ,4 ,5 };

	NUMBER	eNumber(FIVE);

	 //cout << eNumber.ONE << endl;
	cout << eNumber << endl;
	 cout << THREE << endl;
	cout << ONE + TWO << endl;

	int iData = ONE + TWO;
	cout << iData << endl;

	cout << sizeof(NUMBER) << endl;

	return 0;
}

#pragma endregion ����ü

