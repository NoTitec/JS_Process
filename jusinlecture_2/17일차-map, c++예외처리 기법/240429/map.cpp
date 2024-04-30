// 240429.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//������ �Լ���ü��
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
		cout << "ã�� ���Ұ� ����" << endl;

	cout << iter->first << "\t" << iter->second << endl;



	// map �����̳� key ���� ���ڿ��� ��� ������ ����

	// 1. ���� ����(�ƽ�Ű �ڵ� ����) : �ƽ�Ű �ڵ� �� �����̱� ������ ���ĺ� ������ ����
	// 2. ���ڿ� ��� : ���ĺ� ������ �� ��, �ּҰ� ���� ������ �ϰ� ��.
	// 3. string �����̳�(MFC�� CString Ŭ����) : ���ĺ� ������ ����, �����̳� ���ο� ���ڿ� ���� �����ڰ� �־ ��� �񱳸� ������ �����Ͽ� ���� ����

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
	// mapInt.erase(3);		// key �� �������� �߰� ������ ������ �Լ��� �����ε� �Ǿ� ����

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

