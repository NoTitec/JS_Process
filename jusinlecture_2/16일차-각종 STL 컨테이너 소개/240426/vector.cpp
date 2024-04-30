// 240426.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma region vector

//int main()
//{
	//vector 선언하면서 {} 초기화
	//vector<int>		vecInt{1, 2, 3, 4, 5};

	////원하는 크기 벡터 생성
	////vector<int>		vecInt(10);

	//for (size_t i = 0; i < vecInt.size(); ++i)
	//cout << vecInt[i] << endl;

	//cout << "size : " << vecInt.size() << "\tcapacity : " << vecInt.capacity() << endl;

	//cout << "-----------------------------------" << endl;

	//vector<int>		vecInt;
	//vecInt.resize(5);
	//resize함수는 백터 메모리 할당하면서 자동으로 0으로 초기화
	// 원소를 0초기화해놨기때문에 resize후 바로 pushback호출하면
	// vector첫번째가아니라 resize한 크기 위치서부터 삽입됨
	//배열 메모리만 확보해주고 초기화는 제공되지않음
	//따라서 reserve후 pushback하면 첫번째원소위치부터 삽입 잘됨
	//vecInt.reserve(5);

	/*for (size_t i = 0; i < vecInt.size(); ++i)
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



