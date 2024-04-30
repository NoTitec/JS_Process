// 240430.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
public: // private 멤버를 초기화하는 유니폼 초기화 시 반드시 해당 생성자가 있어야 동작이 가능
	CObj(int iX, int iY ) : m_iX(iX), m_iY(iY) {}

public:
	//void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	tagInfo	Get_Info()
	{
		return{ "전사", 50, 60 };
	}

private:
	int		m_iX;
	int		m_iY;

	tagInfo	m_tInfo;
};


int main()
{
	// auto 키워드

	// auto : 사용자가 직접 타입을 지정하지 않아도 변수에 저장된 값에 맞는 타입을 찾아주는 키워드
	
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

	// 범위 기반 for문 : 배열의 인덱스를 넘어가는 위험 동작을 방지 할 수 있는 문법
	
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
	// //원본참조
	// for (auto& i : vectInt)
	// {
	// 	i += 5;
	// 
	// 	cout << i << endl;
	// }
	// //값 복사
	// for (auto i : vectInt)
	// {	
	// 	i += 5;
	// 	cout << i << endl;
	// }

	// 유니폼 초기화

	// int			iArray[5] { 1, 2, 3, 4, 5 };
	 tagInfo		tInfo {" ",100, 200};

	 //클래스 유니폼 초기화는 생성자 정의되어 있어야함
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

	// std::array : 객체 지향 다운 배열을 생성하게 해주는 STL
	// 생성자, 소멸자, 복사 생성자, 대입 연산자가 지원되는 배열

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
	// arrTemp.fill(999);	// 배열의 모든 원소를 해당 매개 변수 값으로 채움
	// 
	// for (auto i : arrTemp)
	// 	cout << i << endl;
	// 	
	// int*	p2 = arrEx.data();	// 배열의 첫 번째 주소를 얻어오는 함수!!!!!
	

    return 0;
}

