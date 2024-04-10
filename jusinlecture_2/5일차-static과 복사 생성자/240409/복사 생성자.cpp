#include "stdafx.h"

#include <stdio.h>
//네오플 입사문제

class CName
{
public:
	CName(const char* pName)
	{
		int iLength = strlen(pName) + 1;
		//동적할당
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, pName);
	}

	CName(const CName& rhs)
	{
		//기본 복사생성자는 아래 주석처럼모든 맴버변수를 단순 1:1 대입연산하는식으로 구현되어있음
		//m_pName = rhs.m_pName;
		
		// 깊은 복사 생성의 예
		int		iLength = strlen(rhs.m_pName) + 1;
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, rhs.m_pName);
		
		cout << "복사 생성자 호출" << endl;
	}

	~CName() { delete[]m_pName; }
public:
	void		PrintN() { printf("%s\n", m_pName); }

private:
	char*		m_pName;
};

void	Draw(CName name) { name.PrintN(); }
//void Draw(CName& name) {name.PrintN();}
int main()
{
	//사용자 정의 생성자로 객체 생성
	CName		Name("neo-peple");

	//매개변수가 객체타입이므로 복사생성자 호출
	//기본생성자인 경우 Draw함수 호출시 Name객체의 주소값을 단순 1:1 복사
	//Draw함수내 객체는 원본인 Name과는 다른 객체임
	//그런데 맴버인 m_pName이 같은 주소를 가르키는중
	//이상황에서 Draw함수가 끝나면 복사된 객체 소멸하며 소멸자호출
	//이때 m_pName을 delete하면 원본의 맴버가 가르키는 공간을 해제해버림
	//이는 복사생성자의 얕은복사의 의한 현상이며 이를 해결하기 위해선
	//1. 복사생성자를 재정의하여 깊은 복사를 수행하던지
	//2. 아니면 함수가 &객체를 받아 원본자체를 받도록하는식으로 해야함
	//깊은복사를 고려해야 하는경우
	//1. 맴버변수가 포인터인경우 2. 생성자,소멸자에서 동적할당제어를하는경우
	Draw(Name);

	return 0;
}


#pragma region 복사 생성자

//class CObj
//{
//public:
//	//기본 생성자 재정의
//	CObj(int _iA) : m_iA(_iA) { cout << "생성자 호출" << endl; }
//	//기본 복사 생성자 재정의
//	CObj(const CObj& rhs) : m_iA(rhs.m_iA)
//	{
//		cout << "복사 생성자 호출" << endl;
//	}
//
//public:
//	void Render() { cout << m_iA << endl; }
//	
//	void Draw(CObj Temp)		// 2. 함수의 매개 변수가 객체 타입인 경우
//	{
//		Temp.Render();
//	}
//
//	CObj		Get_Obj()		// 3. 함수의 반환 타입이 객체 타입인 경우
//	{
//		return *this;
//	}
//private:
//	int		m_iA;
//};
//
//int main()
//{
//	CObj		Origin(500);
//	//Origin.Render();
//
//	CObj		CopyOrigin(Origin);		// 1. 먼저 생성한 객체를 매개 변수로 전달하여 객체를 생성하는 경우
//	CopyOrigin.Render();
//
//	//CObj		TEST(700);
//
//	//Origin.Draw(TEST);
//
//	//Origin.Get_Obj().Render();
//
//	return 0;
//}

#pragma endregion 복사 생성자


