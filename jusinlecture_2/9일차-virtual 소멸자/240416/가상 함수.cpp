#include "stdafx.h"

#pragma region 가상화 예
class CObj1
{
public:
	virtual void		Render() = 0;
};

class CPlayer1 : public CObj1
{
public:
	virtual void		Render() {	cout << "player" << endl;}
	virtual void		Draw() = 0;
};

class CThief : public CPlayer1
{
public:
	virtual void		Render() { cout << "thief" << endl; }
	virtual void		Draw() { cout << "thief Draw" << endl; }
};


int main()
{
	CObj1* pPlayer = new CThief;

	pPlayer->Render();

	return 0;
}

#pragma endregion 가상화 예

#pragma region 가상 소멸자

//class CObj1
//{
//public:
//	CObj1() { cout << "부모 생성자" << endl; }
//	virtual ~CObj1() { cout << "부모 소멸자" << endl; }
//};
//
//class CPlayer1 : public CObj1
//{
//public:
//	CPlayer1() { cout << "자식 생성자" << endl; }
//	~CPlayer1() { cout << "자식 소멸자" << endl; }
//};
//
//int main()
//{
//	/*CObj1*		pObj = new CObj1;
//
//	delete pObj;
//	pObj = nullptr;*/
//
//	CObj1*		pPlayer = new CPlayer1;
//
//	delete pPlayer;
//	pPlayer = nullptr;
//
//
//
//
//	return 0;
//}



#pragma endregion 가상 소멸자
