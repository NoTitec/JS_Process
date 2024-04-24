// 240424.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

int main()
{
	/*vector<int*>		vecIntP;

	vecIntP.push_back(new int);
	vecIntP.push_back(new int);
	vecIntP.push_back(new int);
	vecIntP.push_back(new int);
	
	for (vector<int*>::iterator iter = vecIntP.begin();
		iter != vecIntP.end(); )
	{
		if (충돌)
		{
			Safe_Delete(*iter);
			iter = vecIntP.erase(iter);
		}
		else
			++iter;
	}*/
	

#pragma region 반복자

	//vector<int>				vecInt;
	//
	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);
	//vecInt.push_back(40);

	// 1. 출력 반복자 2. 입력 반복자 3. 순방향(정방향) 반복자 4. 양방향 반복자 5. 임의 접근 반복자
	// *			  *, =		   *, =, ++				 *, =, ++, --	*, =, ++, --, +=, -= 			
	
	//vector<int>::iterator iter = vecInt.begin() + 2; // 임의 접근 반복자이기 때문에 가능
	// iter += 2;	// 임의 접근 반복자이기 때문에 가능
	
	//vecInt.insert(iter, 500);		// 중간 삽입
	//iter = vecInt.erase(iter);

	//cout << (*iter) << endl;

	/*for(iter = vecInt.begin(); iter != vecInt.end(); ++iter)
		cout << (*iter) << endl;*/


	//cout << (*(vecInt.end())) << endl;


	//vecInt.front() = 1234;
	//vecInt.back() = 50000;
	//
	//for (size_t i = 0; i < vecInt.size(); ++i)
	//	cout << vecInt[i] << endl;


	// cout << vecInt.front() << endl;
	// cout << vecInt.back() << endl;


#pragma endregion 반복자
	
#pragma region swap
	// vecInt.clear();
	// 
	// cout << "int :  " << vecInt.size() << "\t" << vecInt.capacity() << endl;
	// //메모리까지 완전 제거
	// // vector<int>().swap(vecInt);
	// vecInt.shrink_to_fit();
	// 
	// cout << "int :  " << vecInt.size() << "\t" << vecInt.capacity() << endl;

	/*vector<int>				vecTemp;

	vecTemp.push_back(100);
	vecTemp.push_back(200);
	vecTemp.push_back(300);

	cout << "int :  " << vecInt.size() << "\t" << vecInt.capacity() << endl;
	cout << "temp : " << vecTemp.size() << "\t" << vecTemp.capacity() << endl;

	vecInt.swap(vecTemp);

	cout << "----------------------------" << endl;
	cout << "int :  " << vecInt.size() << "\t" << vecInt.capacity() << endl;
	cout << "temp : " << vecTemp.size() << "\t" << vecTemp.capacity() << endl;*/
#pragma endregion swap	

#pragma region vector 메모리 특성


	//for (int i = 0; i < 20; ++i)
	//{
	//	cout << "사이즈 : " << vecInt.size() << "\t메모리 개수 : " << vecInt.capacity() << endl;
	//	vecInt.push_back(10);
	//}

	//vecInt.clear();		// 컨테이너 안에 있는 모든 원소를 삭제

	//if (vecInt.empty())	// 컨테이너 안에 원소의 유무를 판단하여 bool 타입을 반환
	//	cout << "vecInt 비어 있음" << endl;

	//else
	//	cout << "vecInt 원소 있음" << endl;

	//cout << "----------------------------------" << endl;
	//cout << "사이즈 : " << vecInt.size() << "\t메모리 개수 : " << vecInt.capacity() << endl;

#pragma endregion vector 메모리 특성

#pragma region 원소 출력 및 pop_back

	// size : 컨테이너 안에 있는 원소 개수 반환

	/*for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "--------------------------" << endl;

	vecInt.pop_back();
	vecInt.pop_back();

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;*/

#pragma endregion 원소 출력 및 pop_back

    return 0;
}

// vector를 이용한 성적표 프로그램 만들기
// 
// 1. (추가)입력 2. 출력 3. 검색 4.삭제 5. 종료