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
//list<int>::iterator		iter = intList.begin(); // +2;	// ���� ���� �ݺ����� ��� ����
// 
// 	// iter += 2;	// ���� ���� �ݺ����� ��� ����
// 	// ++iter;
// 	// ++iter;
// iter�� �տ� ������
 	//intList.insert(iter, 500);
	//���� �� ���� iter ��ȯ
// 	//iter = intList.erase(iter);
// 
// 	//cout << (*iter) << endl;
// 
// 	// for(iter = intList.begin(); iter != intList.end(); ++iter)
// 	// 	cout << (*iter) << endl;
// 	// 
// 	// cout << "--------------------------------" << endl;
//intList.sort(greater<int>());		// �� ���� ������� ����� ��� ��� ���� �Լ�

//����Ʈ ũ�� ���ϴ� �Լ�
//distance(intList.begin(),intList.end());
// 
// 	// intList.sort();
// 	// intList.reverse();		// ���ҵ��� ��ġ�� ������ ������ �Լ�
// 
// 	// intList.splice();		// �߶󳻱� + �ٿ��ֱ�
// 
// 	// intList.remove(30);	// value ���� ��ġ�ϴ� ��带 ��� ����
// 	// intList.remove_if(Sum); // �����ڿ� ���� ���� �Ǵ� ��带 ��� ����
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
	 //�ܼ� ���� ����Ʈ : ++ �����ڷθ� �̵��� ����
	 //���� : ����Ʈ���� ������ ����, ���� ���� �޸𸮸� ���
	
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

	 auto it =ForList.before_begin(); // ù ��° ��� ������ ����Ű�� �ݺ���
	 ForList.insert_after(it, 50);
	 for (forward_list<int>::iterator iter = ForList.begin();
		 iter != ForList.end(); ++iter)
	 {
		 cout << (*iter) << endl;
	 }
	 auto it2 = ForList.before_begin(); // ù ��° ��� ������ ����Ű�� �ݺ���
	 ForList.erase_after(it2);
	 for (forward_list<int>::iterator iter = ForList.begin();
		 iter != ForList.end(); ++iter)
	 {
		 cout << (*iter) << endl;
	 }
	return 0;
}


#pragma endregion forward_list
