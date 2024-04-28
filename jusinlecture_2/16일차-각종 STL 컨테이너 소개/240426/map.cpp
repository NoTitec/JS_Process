#include "stdafx.h"

int main()
{
	map<int, int>		mapInt;
	// map<문자열, 객체 포인터>

	// 1. pair 함수 객체를 이용한 원소 추가
	pair<int, int>		MyMap(1, 100);

	// MyMap.first  = 1;			// key 값
	// MyMap.second = 100;			// value 값
	mapInt.insert(MyMap);

	// 2. pair 임시 객체를 이용한 원소 추가
	mapInt.insert(pair<int, int>(2, 200));

	// 3. make_pair 함수를 이용한 원소 추가
	mapInt.insert(make_pair(3, 300));

	// 4. value_type을 이용한 원소 추가
	map<int, int>::value_type		MyValue(4, 400);

	// MyValue.first = 4;	// const 성격이 부여
	// MyValue.second = 400;	
	mapInt.insert(MyValue);

	// 5. value_type 임시 객체를 이용한 원소 추가(가장 권장하는 방법) 
	mapInt.insert(map<int, int>::value_type(5, 500));

	// 6. [] 연산자를 이용한 원소 추가 (가장 비추하는 방법)
	mapInt[6] = 600;
	mapInt[6] = 9999;

	//////////////////////////////////////////////////////////////
	// 7. 유니폼 초기화를 이용한 원소 추가 (pair 명시적이라 8번보다 선호)
	mapInt.insert({7, 700});

	// 8. emplace 함수를 이용한 원소 추가
	mapInt.emplace(8, 800);

	for (map<int, int>::iterator iter = mapInt.begin();
		iter != mapInt.end(); ++iter)
	{
		cout << iter->first << "\t" << iter->second << endl;
	}


	return 0;
}