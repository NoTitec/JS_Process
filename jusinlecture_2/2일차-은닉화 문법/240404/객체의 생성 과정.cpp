#include "stdafx.h"

class CObj
{
public:
	//CObj()// 명시적으로 구현한 생성자
	//{	
	//	m_iA = 100;			// 대입 연산을 이용한 초기화
	//	cout << "생성자 호출" << endl;	
	//}	

	CObj(int _iA)
	{
		m_iA = _iA;
		cout << "매개 변수가 있는 생성자 호출" << endl;
	}

	~CObj()
	{
		cout << "소멸자 호출" << endl;
	}
 
public:
	void	Render() { cout << m_iA << endl; }

private:
	int			m_iA;
};

int main()
{
	CObj	Obj{ 10 };		// 객체 -> stack 객체 생성
	Obj.Render();

	// 객체 생성 과정

	// 1. 메모리 할당
	// 2. 생성자 호출

	// 객체 소멸 과정

	// 1. 소멸자 호출
	// 2. 메모리 반환


	// 생성자와 소멸자 : 객체의 생성 및 소멸 시점에 반드시 호출되는 함수

	// 생성자는 여러 개가 존재할 수 있음(함수 오버로딩이 성립됨)
	// 생성자와는 달리 소멸자는 오로지 한 개만 존재한다.
	 
	// 객체 생성 시, 컴파일러가 자동적으로 생성하는 함수

	// 1. 기본 생성자(default 생성자)
	// 2. 기본 복사 생성자(default 복사 생성자)
	// 3. 기본 대입 연산자(default 대입 연산자)
	// 4. 기본 소멸자(default 소멸자)

	//Obj.Render();

	//CObj*		pObj1 = new CObj;

	//delete pObj1;
	//pObj1 = nullptr;

	// c언어 문법으로는 클래스의 생성자, 소멸자를 호출하지 못함
	// CObj*		pObj = (CObj*)malloc(sizeof(CObj));	// 객체 생성 실패
	// free(pObj);	// 객체 소멸 실패

	return 0;
}