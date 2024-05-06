#include "stdafx.h"

bool Sum(int iNumber)
{
	return iNumber < 40;
}

#pragma region list
// 
//int main()
//{
// 
	// list<int>		intList;
// 	// 
// intList.push_back(10);
// 	// intList.push_back(20);
// 	// intList.push_back(30);
// 	// intList.push_back(30);
// 	// intList.push_back(40);
// 	// intList.push_back(50);
// 	// intList.push_back(30);
// 	// 
//list<int>::iterator		iter = intList.begin(); // +2;	// 임의 접근 반복자일 경우 가능
// 
// 	// iter += 2;	// 임의 접근 반복자일 경우 가능
// 	// ++iter;
// 	// ++iter;
// iter의 앞에 삽입함
 	//intList.insert(iter, 500);
	//삭제 후 다음 iter 반환
// 	//iter = intList.erase(iter);
// 
// 	//cout << (*iter) << endl;
// 
// 	// for(iter = intList.begin(); iter != intList.end(); ++iter)
// 	// 	cout << (*iter) << endl;
// 	// 
// 	// cout << "--------------------------------" << endl;
//intList.sort(greater<int>());		// 퀵 정렬 기반으로 설계된 노드 기반 정렬 함수

//리스트 크기 구하는 함수
//distance(intList.begin(),intList.end());
// 
// 	// intList.sort();
// 	// intList.reverse();		// 원소들의 배치를 역으로 뒤집는 함수
// 
// 	// intList.splice();		// 잘라내기 + 붙여넣기
// 
// 	// intList.remove(30);	// value 값과 일치하는 노드를 모두 삭제
// 	// intList.remove_if(Sum); // 조건자에 따라 참이 되는 노드를 모두 삭제
// 
// 	/*for (iter = intList.begin(); iter != intList.end(); ++iter)
// 	cout << (*iter) << endl;*/
// 
// 
// 
// #pragma region push_front, pop_front
// 
// 	//intList.push_front(10);
// 	//intList.push_front(20);
// 	//intList.push_front(30);
// 	//intList.push_front(40);
// 
// 	//// for (size_t i = 0; i < intList.size(); ++i)
// 	//// 	cout << intList[i] << endl;
// 
// 	//for (list<int>::iterator iter = intList.begin();
// 	//	iter != intList.end(); ++iter)
// 	//{
// 	//	cout << (*iter) << endl;
// 	//}
// 
// 	//intList.pop_front();
// 	//intList.pop_front();
// 
// 	//cout << "===================================" << endl;
// 
// 	//for (list<int>::iterator iter = intList.begin();
// 	//	iter != intList.end(); ++iter)
// 	//{
// 	//	cout << (*iter) << endl;
// 	//}
// #pragma endregion push_front, pop_front
// 	return 0;
//}


#pragma endregion list

#pragma region forward_list

int main()
{
	 //단순 연결 리스트 : ++ 연산자로만 이동이 가능
	 //장점 : 리스트보다 빠르게 동작, 적은 양의 메모리를 사용
	
	 forward_list<int>	ForList;
	 
	 ForList.push_front(10);
	 ForList.push_front(20);
	 ForList.push_front(30);
	 ForList.push_front(40);
	 
	 for (forward_list<int>::iterator iter = ForList.begin();
	 	iter != ForList.end(); ++iter)
	 {
	 		cout << (*iter) << endl;
	 }
	 
	 int	iCount = distance(ForList.begin(), ForList.end());
	 
	 cout << iCount << endl;

	 auto it =ForList.before_begin(); // 첫 번째 요소 이전을 가리키는 반복자
	 ForList.insert_after(it, 50);
	 for (forward_list<int>::iterator iter = ForList.begin();
		 iter != ForList.end(); ++iter)
	 {
		 cout << (*iter) << endl;
	 }
	 auto it2 = ForList.before_begin(); // 첫 번째 요소 이전을 가리키는 반복자
	 ForList.erase_after(it2);
	 for (forward_list<int>::iterator iter = ForList.begin();
		 iter != ForList.end(); ++iter)
	 {
		 cout << (*iter) << endl;
	 }
	return 0;
}


#pragma endregion forward_list
