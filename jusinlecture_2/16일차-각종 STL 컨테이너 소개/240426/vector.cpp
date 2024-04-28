// 240426.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma region vector
/*
int main()
{
	//vector<int>		vecInt{1, 2, 3, 4, 5};

	//vector<int>		vecInt(10);

	/ *for (size_t i = 0; i < vecInt.size(); ++i)
	cout << vecInt[i] << endl;

	cout << "size : " << vecInt.size() << "\tcapacity : " << vecInt.capacity() << endl;

	cout << "-----------------------------------" << endl;* /

	vector<int>		vecInt;

	//vecInt.resize(5);
	vecInt.reserve(5);

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "size : " << vecInt.size() << "\tcapacity : " << vecInt.capacity() << endl;

	cout << "-----------------------------------" << endl;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "size : " << vecInt.size() << "\tcapacity : " << vecInt.capacity() << endl;


	return 0;
}*/

#pragma endregion vector

#pragma region deque

//int main()
//{
//	deque<int>	dq;
//
//	dq.push_back(10);
//	dq.push_front(20);
//	dq.push_back(30);
//	dq.push_front(40);
//
//	for (size_t i = 0; i < dq.size(); ++i)
//		cout << dq[i] << endl;
//
//	return 0;
//}

#pragma endregion deque



