#include "stdafx.h"

#pragma region 연산자 오버로딩

class CObj
{
public:
	//기본생성자
	CObj() {}
	//인자 두개인 생성자
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) {}

 //기본 대입생성자 재정의
	// Cobj A();
	// Cobj B();
	// A=B;
	CObj& operator =(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;

		// m_pData = rObj.m_pData; 
		// 필요에 따라 깊은 대입(?)이 가능하도록 코드를 설계해야 할 수 있다.

		return *this;
	}
	//기본소멸자
	~CObj() {}

public:
	void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj	operator +(CObj& rObj)
	{
		CObj	Result(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Result;
	}

	CObj	operator +(int _iData)
	{
		CObj	Result(m_iX + _iData, m_iY + _iData);

		return Result;
	}

	CObj&	operator++()	// 전위 연산
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}

	CObj	operator++(int)	// 후위 연산, 전위연산이랑 똑같이생겨서 구분하기 위해
	{
		CObj	Result(*this);

		m_iX += 1;
		m_iY += 1;

		return Result;
	}


private:
	int		m_iX;
	int		m_iY;
	int*	m_pData;
};

CObj	operator+ (int _iData, CObj& rObj)
{
	CObj	Result(rObj + _iData);

	return Result;
}
//
//int main()
//{
//	// 연산자 오버로딩 : 함수 오버로딩의 규칙을 연산자에 적용하는 문법으로, 연산자의 이름을 한 함수를 만들어 제공하는 문법
//	// 연산자 오버로딩은 연산자 기준, 좌측 객체를 기준으로 동작을 수행한다.
//	// 원래 연산자의 기능을 다른 기능으로 바꿀 수 없다.
//
//	// 클래스 멤버로만 오버로딩이 가능한 연산자들
//	// '=', '()', '[]', '->'
//
//
//	// operator <- : 연산자 오버로딩을 위해 사용하는 키워드
//
//	// CObj	Temp(10, 20);
//	// CObj	Src(30, 40);
//
//	// Temp = Temp + Src;
//	//Temp = Temp + 20;
//
//	//Temp = 20 + Temp;
//
//	//++(++Temp);
//	// (Temp++)++;
//
//	// Temp.Render();
//
//
//	return 0;
//}
#pragma endregion 연산자 오버로딩

#pragma region 함수 객체

// 함수 객체 : 객체를 함수처럼 사용하는 문법, ()연산자를 오버로딩하여 생성하는 방식
// STL 알고리즘의 조건자로 사용하기 위해 주로 작성
// 조건자 : BOOL 타입의 반환 형식을 갖는 함수 또는 함수객체로써 참, 거짓에 따라 알고리즘의 수행 여부를 판단 시켜주는 문법

class CPlus
{
public:
	int	operator()(int _iDst, int _iSrc)
	{
		return _iDst + _iSrc;
	}
};

class CSortRule
{
public:
	virtual bool operator()(int _iDst, int _iSrc) = 0;
};

class CAscendingSort : public CSortRule
{
public:
	virtual bool operator()(int _iDst, int _iSrc)
	{
		if (_iDst > _iSrc)
			return true;
		
		else
			return false;

		//return _iDst > _iSrc;
	}
};

class CDescendingSort : public CSortRule
{
public:
	CDescendingSort(int _iData)  : m_iData(_iData){}

public:
	virtual bool operator()(int _iDst, int _iSrc)
	{
		if (_iDst < _iSrc)
			return true;

		else
			return false;

		//return _iDst < _iSrc;
	}

private:
	int		m_iData;
};

bool	Less(int _iDst, int _iSrc)
{
	return _iDst > _iSrc;
}

bool	Greater(int _iDst, int _iSrc)
{
	return _iDst < _iSrc;
}

void	Bubble_Sort(int _iArray[], int _iSize, CSortRule& Functor)
{
	for (int i = 0; i < _iSize; ++i)
	{
		for(int j = 0; j <_iSize - 1; ++j)
		{
			if (Functor(_iArray[j], _iArray[j + 1]))
				swap(_iArray[j], _iArray[j + 1]);
		}
	}
}


int main()
{

	/*CPlus		Functor;
	cout << Functor(10, 20) << endl;*/


	int		iArray[5] = { 5, 1, 2, 4, 3 };

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << "\t";

	cout << endl;
		
	CDescendingSort	DESCE(10);

	Bubble_Sort(iArray, 5, CDescendingSort(10));
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << "\t";

	return 0;
}

#pragma region 임시 객체

////////////////////////////////임시 객체////////////////////////
//// 임시 객체 : 이름 없이 임시 메모리 공간에 생성되는 객체
//class CTest
//{
//public:
//	CTest(char* pName)
//	{
//		strcpy_s(m_szName, sizeof(m_szName), pName);
//		cout << m_szName << " 생성자" << endl;
//	}
//	~CTest()
//	{
//		cout << m_szName << " 소멸자" << endl;
//	}
//
//private:
//	char		m_szName[32];
//};
//
//int main()
//{
//	CTest		Test("일반 객체");
//
//	cout << "-------------임시 객체 생성 중------------------" << endl;
//
//	CTest("임시 객체");
//
//	cout << "-------------임시 객체 소멸 완료------------------" << endl;
//
//	return 0;
//}

#pragma endregion 임시 객체

#pragma endregion 함수 객체

// string 클래스  =, +, == 직접 구현해봐라