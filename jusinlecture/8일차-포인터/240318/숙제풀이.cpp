#include <iostream>

using namespace std;

int	Factorial(int _iNumber);

int main()
{
	// cout << Factorial(100) << endl;
	// cout << 5 * 4 * 3 * 2 * 1 << endl;

	return 0;
}

int	Factorial(int _iNumber)
{
	if (0 == _iNumber)
		return 1;

	return _iNumber * Factorial(_iNumber - 1);
}