// 240404.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "Define.h"

// 멤버 변수(데이터) + 멤버 함수(기능)

// 1. 접근 제어 지시자를 이용한 은닉화 문법
// 2. access method를 이용한 데이터 접근

class CObj
{
public:
	void		Render();	// 멤버 함수

public:		// access method
	void		Set_Hp(int _iHp)	{ m_iHp = _iHp; }
	int			Get_Hp()			{ return m_iHp; }

	void		Set_Attack(int _iAttack) { m_tInfo.iAttack = _iAttack; }
	INFO		Get_Info() { return m_tInfo; }

private :
	int		m_iHp;		// 멤버 변수
	INFO	m_tInfo;
};

//void	Render()		// 전역 함수
void	CObj::Render()	// 멤버 함수
{
	cout << m_iHp << endl;
}
struct tagInfo
{
public :
	int		iHp;
};

int main()
{
	// C++
	// OOP + Generic Programming

	// 클래스의 4대 속성
	// 은닉화, 캡슐화, 상속성, 다형성



	/*tagInfo	tInfo = { 100 };

	tInfo.iHp = 200;

	cout << tInfo.iHp << endl;*/

	 CObj	Obj;

	 Obj.Set_Hp(100);
	
	 cout << Obj.Get_Hp() << endl;

	 cout << Obj.Get_Info().iAttack << endl;

	 //Obj.Render();
	
	
	 //cout << tInfo.m_iHp << endl;


    return 0;
}

// 성적표 프로그램을 클래스로 만들고 동적 배열을 구현하라

//- 입력을 누르면 몇 명을 입력할 지 묻고 입력을 받음
//- 출력을 누르면 출력
//- 입력을 다시 누르면 추가 입력이 되도록 만들 것