#include "stdafx.h"

int	g_iNumber = 50;

class CObj
{
public:
	CObj() : m_iA(100), m_iB(200)			// 생성자 이니셜라이저 : 멤버인 상수 초기화가 목적
	{ 
		//m_iA = 100; 
	}
	CObj(int _iA, int _iB) : m_iA(_iA), m_iB(_iB) {}

public:
	void	Render() { cout << m_iA << endl; }
	
	void	Print()const;
	void	Print();
	
	void	Draw() const;

private:
	const int		m_iA;
	int				m_iB;
};
void CObj::Print() const
{
	cout << "jusin academy" << endl;
}

void CObj::Print()
{
	cout << "school" << endl;
}


void	CObj::Draw() const			// 멤버 변수에 대해 읽기 전용인 함수를 의미
{
	// int		iData(0);
	// iData = 100;
	// cout << iData << endl;
	// 
	// g_iNumber = 500;
	// cout << g_iNumber << endl;
	// 
	// m_iB = 2000;
	// cout << m_iB << endl;

	cout << "hello world" << endl;

	Print();			// const 가 붙지 않은 멤버 함수를 호출하려는 경우 멤버 변수의 쓰기가 허용될 수 있기 때문에 컴파일러가 에러를 일으킴
}

int main()
{
	// 객체 생성 시, const의 여부에 따른 함수 오버로딩 적용 예

	//const CObj		Obj;

	//Obj.Render();
	//Obj.Draw();
	//Obj.Print();

	const CObj*		pObj = new CObj;

	pObj->Print();

	delete pObj;
	pObj = nullptr;

	return 0;
}