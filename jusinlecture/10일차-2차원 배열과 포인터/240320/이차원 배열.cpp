#include <iostream>

using namespace std;

int main()
{
		//		  [��][��]
	int		iArray[2][3] = 
	{ 
		{ 1, 2, 3 }, // 0��
		{ 4, 5, 6 }  // 1��
	   //0�� 1�� 2��
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

	// 2���� �迭 ������

	// �ڷ���(*������)[��]
	// void Render(int(*pArray)[3]);

	//int(*pArray)[3] = iArray;
	//cout << pArray[1][1] << endl;

	return 0;
}