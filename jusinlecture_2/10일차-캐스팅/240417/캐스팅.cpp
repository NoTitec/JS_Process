// 240417.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CObj
{
public:
	virtual ~CObj() {}
};
class CPlayer{};
class CPlayer2 : public CObj 
{
public:
	void	Render() { cout << "player2" << endl; }
};

int main()
{
	// static_cast, dynamic_cast, const_cast, reinterpret_cast

#pragma region static_cast 연산자

	//int		iNumber = (int)3.14;

	// static_cast : 정적 캐스팅, 형 변환 시점이 컴파일 타임, c언어 시절의 캐스트와 거의 같음
	// c언어의 캐스팅 보다는 안정적
	// static_cast의 논리적인 형 변환의 기준 : 클래스가 상속 관계에 있으면 논리적이라고 판단

	// 위험성 : 컴파일 타임에 수행하는 형 변환이어서 런 타임 시, 타입 체크가 되지 않아 위험한 변환을 인지하지 못한다.

	// int		iNumber = static_cast<int>(3.14);
	// cout << iNumber << endl;

	// CPlayer*	pPlayer = new CPlayer;

	// CObj*		pObj = (CObj*)pPlayer;	// c언어
	// CObj*		pObj2 = static_cast<CObj*>(pPlayer);	// 논리적인 형 변환이 아닌 경우 캐스팅을 허용하지 않음

	// CObj*		pObj = new CObj;
	// 
	// CPlayer2*	pPlayer = static_cast<CPlayer2*>(pObj);		
	// pPlayer->Render();

#pragma endregion static_cast 연산자

#pragma region dynamic_cast 연산자

	// dynamic_cast 연산자 : 런 타임에 캐스팅을 수행
	// 
	// 1. 일반 자료형 또는 일반 자료형 포인터는 사용 할 수 없음
	// 2. 객체 포인터 간의 형 변환을 대상으로 삼음(down casting용)
	// 3. 부모와 자식이라는 클래스 상속 관계여야 함
	// 4. 부모 클래스에 가상 함수가 하나라도 있어야 사용 가능
	// 5. 비논리적인 캐스팅인 경우 nullptr을 반환


	//CObj*		pObj = new CObj;
	//CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);
	//CPlayer2*	pPlayer2 = dynamic_cast<CPlayer2*>(pObj);

	//if (nullptr == pPlayer2)
	//	cout << "이상해" << endl;

	//pPlayer2->Render();

	/*CObj*		pObj = new CPlayer2;

	static_cast<CPlayer2*>(pObj)->Render();
	dynamic_cast<CPlayer2*>(pObj)->Render();*/


#pragma endregion dynamic_cast 연산자

#pragma region const_cast 연산자

	// const_cast : const의 성향을 제거하는 캐스팅 연산자, 단, 포인터나 레퍼런스 형만 가능

	// const int iData = 10;
	// const_cast<int>(iData) += 10;

	// int		iNumber(10);
	// 
	// const int*		ptr = &iNumber;		// 읽기 전용 포인터
	// 
	// int*	ptr2 = const_cast<int*>(ptr);
	// 
	// *ptr2 = 20;
	// 
	// cout << iNumber << endl;

#pragma endregion const_cast 연산자

#pragma region reinterpret_cast

	// reinterpret_cast : const 포인터를 제외한 모든 포인터의 형 변환을 허용, 비 논리적인 형 변환도 허용
	// 예측 할 수 없는 결과를 초래하기 때문에 사용을 자제할 것을 권장

	// CPlayer2*	pPlayer = new CPlayer2;
	// CObj*		pObj = reinterpret_cast<CObj*>(pPlayer);

	// int		iNumber(65);
	// char*	ptr = reinterpret_cast<char*>(&iNumber);
	// cout << ptr << endl;
	
#pragma endregion reinterpret_cast

    return 0;
}

