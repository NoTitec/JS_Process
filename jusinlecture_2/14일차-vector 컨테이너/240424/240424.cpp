// 240424.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		if (�浹)
		{
			Safe_Delete(*iter);
			iter = vecIntP.erase(iter);
		}
		else
			++iter;
	}*/
	

#pragma region �ݺ���

	//vector<int>				vecInt;
	//
	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);
	//vecInt.push_back(40);

	// 1. ��� �ݺ��� 2. �Է� �ݺ��� 3. ������(������) �ݺ��� 4. ����� �ݺ��� 5. ���� ���� �ݺ���
	// *			  *, =		   *, =, ++				 *, =, ++, --	*, =, ++, --, +=, -= 			
	
	//vector<int>::iterator iter = vecInt.begin() + 2; // ���� ���� �ݺ����̱� ������ ����
	// iter += 2;	// ���� ���� �ݺ����̱� ������ ����
	
	//vecInt.insert(iter, 500);		// �߰� ����
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


#pragma endregion �ݺ���
	
#pragma region swap
	// vecInt.clear();
	// 
	// cout << "int :  " << vecInt.size() << "\t" << vecInt.capacity() << endl;
	// //�޸𸮱��� ���� ����
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

#pragma region vector �޸� Ư��


	//for (int i = 0; i < 20; ++i)
	//{
	//	cout << "������ : " << vecInt.size() << "\t�޸� ���� : " << vecInt.capacity() << endl;
	//	vecInt.push_back(10);
	//}

	//vecInt.clear();		// �����̳� �ȿ� �ִ� ��� ���Ҹ� ����

	//if (vecInt.empty())	// �����̳� �ȿ� ������ ������ �Ǵ��Ͽ� bool Ÿ���� ��ȯ
	//	cout << "vecInt ��� ����" << endl;

	//else
	//	cout << "vecInt ���� ����" << endl;

	//cout << "----------------------------------" << endl;
	//cout << "������ : " << vecInt.size() << "\t�޸� ���� : " << vecInt.capacity() << endl;

#pragma endregion vector �޸� Ư��

#pragma region ���� ��� �� pop_back

	// size : �����̳� �ȿ� �ִ� ���� ���� ��ȯ

	/*for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "--------------------------" << endl;

	vecInt.pop_back();
	vecInt.pop_back();

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;*/

#pragma endregion ���� ��� �� pop_back

    return 0;
}

// vector�� �̿��� ����ǥ ���α׷� �����
// 
// 1. (�߰�)�Է� 2. ��� 3. �˻� 4.���� 5. ����