// 240430.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct tagInfo
{
	char* pName;
	int	x;
	int y;
};

class CObj
{
public: // private ����� �ʱ�ȭ�ϴ� ������ �ʱ�ȭ �� �ݵ�� �ش� �����ڰ� �־�� ������ ����
	CObj(int iX, int iY ) : m_iX(iX), m_iY(iY) {}

public:
	//void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	tagInfo	Get_Info()
	{
		return{ "����", 50, 60 };
	}

private:
	int		m_iX;
	int		m_iY;

	tagInfo	m_tInfo;
};


int main()
{
	// auto Ű����

	// auto : ����ڰ� ���� Ÿ���� �������� �ʾƵ� ������ ����� ���� �´� Ÿ���� ã���ִ� Ű����
	
	// auto	a = true;
	// auto	b = 'A';
	// auto	c = "hello";
	// auto	d = 3;
	// auto	e = 3.14f;
	// auto	f = 5.223;
	// 
	// auto	p = new CObj;
	// auto&	r = d; 

	// vector<int>		vecInt;
	// 
	// vecInt.push_back(10);
	// vecInt.push_back(20);
	// vecInt.push_back(30);
	// vecInt.push_back(40);
	// 
	// vector<int>::iterator	iter = vecInt.begin();
	// auto	iter = vecInt.begin();

	// ���� ��� for�� : �迭�� �ε����� �Ѿ�� ���� ������ ���� �� �� �ִ� ����
	
	//int		iArray[5] = { 1, 2, 3, 4, 5 };

	//for (int i = 0; i < 8; ++i)
		//cout << iArray[i] << endl;

	//for (int i : iArray)
		//cout << i << endl;

	// vector<int>		vectInt;
	// 
	// vectInt.push_back(10);
	// vectInt.push_back(20);
	// vectInt.push_back(30);
	// vectInt.push_back(40);
	// //��������
	// for (auto& i : vectInt)
	// {
	// 	i += 5;
	// 
	// 	cout << i << endl;
	// }
	// //�� ����
	// for (auto i : vectInt)
	// {	
	// 	i += 5;
	// 	cout << i << endl;
	// }

	// ������ �ʱ�ȭ

	// int			iArray[5] { 1, 2, 3, 4, 5 };
	 tagInfo		tInfo {" ",100, 200};

	 //Ŭ���� ������ �ʱ�ȭ�� ������ ���ǵǾ� �־����
	 CObj	Obj{ 10, 20 };
	// Obj.Render();
	// 
	// vector<int>		vecInt{ 1, 2, 3, 4, 5 };
	// 
	// for (auto& i : vecInt)
	// 	cout << i << endl;
	// 
	// map<int, int>	mapInt{ {1, 100},{ 2, 200 },{ 3, 300 } };
	// 
	// for (auto i : mapInt)
	// {
	// 	cout << i.first << "\t" << i.second << endl;
	// }

	// std::array : ��ü ���� �ٿ� �迭�� �����ϰ� ���ִ� STL
	// ������, �Ҹ���, ���� ������, ���� �����ڰ� �����Ǵ� �迭

	// int		iArray[5]{ 1, 2, 3, 4, 5 };
	// int		iTemp[5] {  };
	// 
	// cout << sizeof(iArray) / sizeof(int) << endl;
	// cout << size(iArray) << endl;
	// 
	// int*	p = iArray;
	// 
	// array<int, 5>	arrEx{ 10, 20 , 30 ,40, 50 };
	// array<int, 5>	arrTemp = arrEx;
	// 
	// //cout << arrEx.size() << endl;
	// 
	// for (auto i : arrTemp)
	// 	cout << i << endl;
	// 
	// cout << "----------------------------" << endl;
	// 
	// arrTemp.fill(999);	// �迭�� ��� ���Ҹ� �ش� �Ű� ���� ������ ä��
	// 
	// for (auto i : arrTemp)
	// 	cout << i << endl;
	// 	
	// int*	p2 = arrEx.data();	// �迭�� ù ��° �ּҸ� ������ �Լ�!!!!!
	

    return 0;
}

