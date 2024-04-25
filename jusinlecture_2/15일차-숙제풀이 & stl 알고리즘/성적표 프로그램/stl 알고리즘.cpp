#include "stdafx.h"


template<typename T>
bool	Less(T a, T b)
{
	return a < b;
}

template<typename T>
bool	Greater(T a, T b)
{
	return a > b;
}

struct tagLess
{
	template<typename T>
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

template<typename T>
bool IsOddNumber(T Number)
{
	if (0 != Number % 2)
		return true;

	return false;
}

template<typename T>
bool		MaxNumber(T Number)
{
	if (30 < Number)
		return true;

	return false;
}

struct tagEqual
{
	tagEqual(int _iData) : iData(_iData) {}

	bool operator()(int _iNumber)
	{
		if (iData == _iNumber)
			return true;

		return false;
	}

	int			iData;
};


int main()
{
#pragma region sort
	// int		iArray[5] = { 5, 1, 2, 4, 3 };
	// 
	// for (size_t i = 0; i < size(iArray); ++i)
	// 	cout << iArray[i] << "\t";
	// 
	// // sort : �� ������ ����� ���� �Լ�(�Լ� ���ø����� �������), �迭 ��� �������
	// // ����� �����̳��� ������ sort �˰����� ��� �� �� ����.
	// 
	// // sort(begin(iArray), end(iArray), Greater<int>);
	// // sort(begin(iArray), end(iArray), tagLess());
	// sort(begin(iArray), end(iArray), less<int>());
	// 
	// cout << endl;
	// cout << "--------------------------------------" << endl;
	// 
	// for (size_t i = 0; i < size(iArray); ++i)
	// 	cout << iArray[i] << "\t";

	// vector<int>		vecInt;
	// 
	// for(int i = 0; i < 100; ++i)
	// 	vecInt.push_back(rand() % 100);
	// 
	// sort(vecInt.begin(), vecInt.end(), greater<int>());
#pragma endregion sort

#pragma region count_if

	// count_if  : �����ڿ� ���� �Ǵ� ������ ������ ��ȯ

	// vector<int>		vecInt;
	//  
	// for (int i = 0; i < 10; ++i)
	// {
	// 	vecInt.push_back(rand() % 100);
	// 	cout << vecInt[i] << endl;
	// }
	// 
	// int iCount = count_if(vecInt.begin(), vecInt.end(), IsOddNumber<int>);
	// 
	// cout << "Ȧ���� ���� : " << iCount  << endl;	

#pragma endregion count_if

#pragma region for_each

	// for_each : for���� ������

#pragma endregion for_each

#pragma region find_if

	// find_if : �����ڿ� ���ǿ� �´� ���Ҹ� ã�� iterator�� ��ȯ, �׷��� ���ǿ� �´� ���Ұ� ���� ��� end�� ����

	// vector<int>		vecInt;
	// 
	// vecInt.push_back(10);
	// vecInt.push_back(20);
	// vecInt.push_back(30);
	// vecInt.push_back(40);
	// 
	// //vector<int>::iterator	iter = find_if(vecInt.begin(), vecInt.end(), MaxNumber<int>);
	// 
	// vector<int>::iterator	iter = find_if(vecInt.begin(), vecInt.end(), tagEqual(50));
	// 
	// if (iter == vecInt.end())
	// 	cout << "�� ã��" << endl;
	// 
	// else
	// 	cout << (*iter) << endl;
	
#pragma endregion find_if
	
	return 0;
}