#include "stdafx.h"

class CObj
{
public:
	void		Render() { cout << "hello world" << endl; }

public:
	CObj() {
		this->m_iA = 100;
		cout << "부모 생성자" << endl; }
	~CObj() { cout << "부모 소멸자" << endl; }

protected:
	int			m_iA;
};

// #include "Obj.h"	// 자식 클래스의 헤더 파일에는 반드시 부모 클래스의 헤더 파일을 포함해야 한다.

class CPlayer2 : public CObj
{
public:
	CPlayer2() 
	{
		this->m_iA = 200;
		cout << "자식 생성자" << endl; }
	~CPlayer2() { cout << "자식 소멸자" << endl; }

public:
	void	Draw() { 
		cout << m_iA << endl;
		cout << "jusin academy" << endl; 
	}
};

class CMonster2 : public CObj
{
public:
	CMonster2()
	{
		m_iA = 300;
		cout << "자식 생성자" << endl;
	}
	~CMonster2() { cout << "자식 소멸자" << endl; }

public:
	void	Draw() {
		cout << m_iA << endl;
		cout << "jusin academy" << endl;
	}
};

int main()
{
	// 상속의 목적
	// 
	// 1. 부모 클래스(base)의 데이터와 기능을 사용 할 수 있도록 함
	// 2. 공통의 자료형을 사용하게 함

	//CObj	Obj;
	//Obj.Draw();

	 CPlayer2		Player;
	 Player.Draw();
	// Player.Render();

	 CMonster2		Monster;
	 Monster.Draw();


	// 자식 객체의 생성 과정
	// 1. 메모리 할당 2. 부모 생성자 호출 3. 자식 생성자 호출

	// 자식 객체의 소멸 과정
	// 1. 자식 소멸자 호출 2. 부모 소멸자 호출 3. 메모리 반환


	return 0;
}