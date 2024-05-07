#include "stdafx.h"
#include <windows.h>

class CObj
{
public:
	CObj() : m_iX(0), m_iY(0) {}
	CObj(int& _iX, int& _iY) : m_iX(_iX), m_iY(_iY) {}

public:
	void		Render() { cout << m_iX << "\t" << m_iY << endl; }

private:
	int		m_iX;
	int		m_iY;
};

CObj*	Create(int&& iX,  int&& iY)
{
	return new CObj(iX, iY);
}


class CMyArray
{
public:
	CMyArray() : m_pArray(nullptr), m_iSize(0){}
	CMyArray(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) {}
	//복사 생성자
	CMyArray(const CMyArray& rhs)
		: m_pArray(new int[rhs.m_iSize]), m_iSize(rhs.m_iSize)
	{
		memcpy(m_pArray, rhs.m_pArray, sizeof(int) * rhs.m_iSize);
	}
	//이동 생성자
	CMyArray (CMyArray&& rMove) noexcept
	{
		m_pArray = rMove.m_pArray;
		m_iSize  = rMove.m_iSize;

		// 이동 후 null초기화 : 소유권 이전
		rMove.m_pArray = nullptr;
	}



	~CMyArray()
	{
		if (m_pArray)
		{
			delete[] m_pArray;
			m_pArray = nullptr;
		}
	}

private:
	int*		m_pArray;
	int			m_iSize;
};


int main()
{
	// 람다 표현식(람다식) : 무명의 인라인 함수

	// 조건자로 사용하는 함수객체의 불편함(단점)을 보완하기 위해 등장한 문법
	
	// 함수 객체의 단점 : 작성에 용이하지 못함, 사용 시점에 일반 함수와의 구분이 어려움
	// 람다식의 장점 : 작성이 간편하고, 가독성이 증대됨.

	/////////////////////////////////////////////////////////////////////////

	// 기본적인 람다식 문법

	// [] : 람다 소개자, 캡처절 이라고 부름, 컴파일러가 람다식이라는 것을 인지
	// () : 파라미터 지정자, 매개 변수를 전달 받는 일반 함수의 기능과 동일
	// {} : 람다 몸체, 일반 함수의 몸체와 같은 의미

	// []() { cout << "hello world" << endl; }();
	// [](int iData = 50) { cout << iData << endl; }();

	// 묵시적 반환(반환 타입 표기가 생략되어 있다면 컴파일러가 람다 함수 몸체 내부에서 묵시적으로 반환 값을 추론)
	// int	iResult = [](int iDst, int iSrc) { return iDst + iSrc;  }(10, 20);

	// 명시적 반환의 예
	// int	iResult = [](int iDst, int iSrc)-> int { return iDst + iSrc;  }(10, 20);
	// cout << iResult << endl;

	//  (ex1)
	//  vector<int>		vecInt{ 10, 20, 30 , 40, 50 };
	//  for_each(vecInt.begin(), vecInt.end(), [](int n) { cout << n << endl; });

	//  (ex2)
	//  vector<int>		vecInt{ 10, 20, 33, 40, 50 };
	//  
	//  auto iter = find_if(vecInt.begin(), vecInt.end(), 
	//  [](int n)->bool
	//  {
	//  	return 0 != n % 2;
	//  });
	//  
	//  cout << *iter << endl;

	//
	// (ex3)
	//vector<int>		vecInt{ 1, 2, 3, 4, 5 };
	// 
	// int iEvenSum(0), iOddSum(0);
	// 
	// for_each(vecInt.begin(), vecInt.end(), 
	//// [iEvenSum, iOddSum](int n)			// 값 복사에 의한 캡처(const 성격이 부여) : 읽기 전용 용도로 캡처
	//// [iEvenSum, iOddSum](int n) mutable	// 값 복사에 의한 캡처(const 성격이 부여 되었지만 mutable로 쓰기 가능) : 원본 값 변경은 여전히 불가능
	//   [&iEvenSum, &iOddSum](int n)			// 직접 참조에 의한 캡처 : 원본 값 참조가 가능
	// {
	// 	if (0 == n % 2)
	// 		iEvenSum += n;
	// 
	// 	else
	// 		iOddSum += n;
	// });
	// 
	// cout << "짝수 합 : " << iEvenSum << endl;
	// cout << "홀수 합 : " << iOddSum << endl;


	// R-Value 레퍼런스 

	 int		iData(10);
	 int&	r = iData;
	 r = 20;
	 //int& rt = 2;
	 const int&	r2 = 10;
	// 
	// 
	 int&&	rr = 999;
	// 
	// cout << rr << endl;
	// 
	 rr = 200;
	// 
	// cout << rr << endl;

	 CObj* pPlayer = Create(100, 200);
	// pPlayer->Render();
	// delete pPlayer;

	// 이동 생성자  

	CMyArray			Array1(100000000);
	// DWORD			dwTime = GetTickCount();

	CMyArray			Copy(Array1);
	CMyArray			Moving(std::move(Array1));

	// std::move : 매개 변수로 전달 받은 대상을 r-value 레퍼런스로 캐스팅해주는 함수
	// cout << GetTickCount() - dwTime << endl;


	// decltype 키워드 : 주어진 표현식의 타입을 컴파일러가 직접 추론하여 결정하게끔 지시하는 키워드
	//안씀 그냥 auto씀
	// int	iSrc(10);
	// decltype(iSrc)	iDst = 500;
	
	return 0;
}