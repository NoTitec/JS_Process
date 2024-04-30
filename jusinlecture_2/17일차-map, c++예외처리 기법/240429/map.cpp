// 240429.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//조건자 함수객체용
struct tagFinder
{
	tagFinder(char* pTag) : m_pTag(pTag) {}

	template<typename T>
	bool operator()(T& MyPair)
	{
		return !strcmp(MyPair.first, m_pTag);
	}
	
	const char*		m_pTag;
};


int main()
{

	map<const char*, int>			mapInt;


	mapInt.insert({ "AAA", 10 });
	mapInt.insert({ "BBB", 20 });
	mapInt.insert({ "CCC", 30 });

	//map<const char*, int>::iterator	iter = mapInt.find("BBB");

	map<const char*, int>::iterator	iter = find_if(mapInt.begin(), mapInt.end(), tagFinder("BBB"));

	if (iter == mapInt.end())
		cout << "찾는 원소가 없음" << endl;

	cout << iter->first << "\t" << iter->second << endl;



	// map 컨테이너 key 값이 문자열인 경우 정렬의 관계

	// 1. 원시 문자(아스키 코드 문자) : 아스키 코드 값 기준이기 때문에 알파벳 정렬이 가능
	// 2. 문자열 상수 : 알파벳 정렬이 안 됨, 주소값 기준 정렬을 하게 됨.
	// 3. string 컨테이너(MFC의 CString 클래스) : 알파벳 정렬이 가능, 컨테이너 내부에 문자열 관련 조건자가 있어서 대소 비교를 스스로 실행하여 정렬 가능

	// map<int, int, greater<int>>		mapInt;
	// 
	// mapInt.insert({ 1, 100 });
	// mapInt.insert({ 2, 200 });
	// mapInt.insert({ 3, 300 });
	// mapInt.insert({ 4, 400 });
	// mapInt.insert({ 5, 500 });
	// 
	// 
	// map<int, int>::iterator		iter = mapInt.begin();
	// 
	// for (iter = mapInt.begin(); iter != mapInt.end(); ++iter)
	// {
	// 	cout << iter->first << "\t" << iter->second << endl;
	// }

	//++iter;
	//++iter;

	// mapInt.insert({ 13, 1300 });

	// iter = mapInt.erase(iter);
	// mapInt.erase(3);		// key 값 기준으로 중간 삭제가 가능한 함수가 오버로딩 되어 있음

	//cout << iter->first << "\t" << iter->second << endl;

	//for (iter = mapInt.begin(); iter != mapInt.end(); ++iter)
	//{
	//	cout << iter->first << "\t" << iter->second << endl;
	//}



	//iter += 2;

	//cout << iter->first << "\t" << iter->second << endl;

	//cout << mapInt[3] << endl;

	
    return 0;
}

