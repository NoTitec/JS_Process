#include "stdafx.h"

int main()
{
	map<int, int>		mapInt;
	// map<���ڿ�, ��ü ������>

	// 1. pair �Լ� ��ü�� �̿��� ���� �߰�
	pair<int, int>		MyMap(1, 100);

	// MyMap.first  = 1;			// key ��
	// MyMap.second = 100;			// value ��
	mapInt.insert(MyMap);

	// 2. pair �ӽ� ��ü�� �̿��� ���� �߰�
	mapInt.insert(pair<int, int>(2, 200));

	// 3. make_pair �Լ��� �̿��� ���� �߰�
	mapInt.insert(make_pair(3, 300));

	// 4. value_type�� �̿��� ���� �߰�
	map<int, int>::value_type		MyValue(4, 400);

	// MyValue.first = 4;	// const ������ �ο�
	// MyValue.second = 400;	
	mapInt.insert(MyValue);

	// 5. value_type �ӽ� ��ü�� �̿��� ���� �߰�(���� �����ϴ� ���) 
	mapInt.insert(map<int, int>::value_type(5, 500));

	// 6. [] �����ڸ� �̿��� ���� �߰� (���� �����ϴ� ���)
	mapInt[6] = 600;
	mapInt[6] = 9999;

	//////////////////////////////////////////////////////////////
	// 7. ������ �ʱ�ȭ�� �̿��� ���� �߰� (pair ������̶� 8������ ��ȣ)
	mapInt.insert({7, 700});

	// 8. emplace �Լ��� �̿��� ���� �߰�
	mapInt.emplace(8, 800);

	for (map<int, int>::iterator iter = mapInt.begin();
		iter != mapInt.end(); ++iter)
	{
		cout << iter->first << "\t" << iter->second << endl;
	}


	return 0;
}