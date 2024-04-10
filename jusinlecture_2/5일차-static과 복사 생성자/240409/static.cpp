// 240409.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//일반전역변수
int		g_iNumber = 100;

class CObj
{
public:
	//static 클래스 맴버변수는 선언순간 클래스 맴버변수가아니라 내부서 대입이나 초기화 안됨
	CObj()// : m_iA(100)
	{
		//m_iA = 100;
	}

public:
	void	Render()
	{
		cout << m_iA << endl;
	}

	void		Add()	{		m_iA++;	}

	static		void	Print()
	{
		int		iData = 10;
		iData = 20;
		cout << iData << endl;

		g_iNumber = 300;
		cout << g_iNumber << endl;
		
		//m_iB = 4000;				// 클래스의 멤버 변수 읽기와 쓰기를 모두 허용하지 않음(static 함수는 class내부변수 사용 불가)
		// cout << m_iB << endl;

		//static 변수는 사용가능
		m_iA = 200;
		cout << m_iA << endl;
	}

private:
	//class 맴버변수 또는 class 변수라고 호칭
	static int		m_iA;	// 같은 타입의 객체인 경우 메모리 공간을 공유하여 사용 class 2개든 여러개든 다같이 공유
	int				m_iB;
};

//외부서 초기화할때 namespace 필수
int		CObj::m_iA = 100;

int main()
{
	//static 함수도 마찬가지로 외부서 사용시 namespace 필요
	CObj::Print();


	/*CObj		Obj;

	Obj.Add();
	Obj.Add();
	Obj.Add();

	Obj.Render();

	cout << "---------------------------" << endl;

	CObj		Temp;

	Temp.Add();
	Temp.Add();
	Temp.Add();
	
	Temp.Render();*/

	//cout << CObj::m_iA << endl;

	//Obj.Render();

    return 0;
}

