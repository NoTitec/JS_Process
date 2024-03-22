#include <iostream>

using namespace std;

int main()
{
		//		  [행][열]
	int		iArray[2][3] = 
	{ 
		{ 1, 2, 3 }, // 0행
		{ 4, 5, 6 }  // 1행
	   //0열 1열 2열
	};

	//cout << iArray[1][1] << endl;

	cout << (&iArray[0][0]) << endl;
	cout << iArray[0] << endl;
	cout << iArray << endl;

	cout << "-----------------------" << endl;

	cout << (&iArray[0][0]) << endl;
	cout << iArray[0] << endl;
	cout << iArray[1] << endl;
	cout << iArray << endl;

	cout << "-----------------------" << endl;

	int*	p = &iArray[0][0];

	int*	p2 = iArray[0];
	
	int*	p3 = iArray[1];

	cout << p << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	cout << "-------------------------" << endl;

	// 2차원 배열 포인터

	// 자료형(*변수명)[열]
	// void Render(int(*pArray)[3]);

	//int(*pArray)[3] = iArray;
	//cout << pArray[1][1] << endl;

	return 0;
}