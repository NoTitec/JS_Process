// 240415.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// 추상 클래스 : 순수 가상 함수가 한 개라도 있는 클래스

class CObj
{
public:
	virtual void	Render() = 0;		// 순수 가상 함수(overring을 위한 구실)
	virtual void	Draw() { cout << "Obj Draw" << endl; }
};

class CPlayer : public CObj
{
public:
	void	Render() { cout << "player" << endl; }
};

class CMonster : public CObj
{
public:
	void	Render() {}
};

	
int main()
{
	// 오버 라이딩의 조건
	// 
	// 1. 부모와 자식이라는 상속 관계여야 함
	// 2. 부모와 자식 클래스의 형태가 완벽히 일치하는 함수가 존재해야 한다.
	// 3. 부모 클래스의 함수 앞에 반드시 virtual 키워드가 삽입 되어야 한다.

	//cout << sizeof(CObj) << endl;
	//
	//cout << sizeof(CPlayer) << endl;

	// CObj Obj;
	// Obj.Render();

	// CPlayer		Player;
	// Player.Render();

	CObj*		pObj = new CMonster;
	//__vfptr = 0x00e58c4c {240415.exe!const CObj::`vftable'} {0x00e514a6 {240415.exe!CObj::Render(void)}, 0x00e514ce {240415.exe!CObj::Draw(void)}}
	//pObj->Render();

	//CObj*		pPlayer = new CPlayer;
	//__vfptr = 0x00e58d4c {240415.exe!const CPlayer::`vftable'} {0x00e514c4 {240415.exe!CPlayer::Render(void)}, 0x00e514ce {240415.exe!CObj::Draw(void)}}
	//pPlayer->Render();

	/*CObj*	pPlayer = new CPlayer;

	pPlayer->Render();

	delete pPlayer;
	pPlayer = nullptr;*/

	// 1. 부모 함수
	// 2. 자식 함수
	// 3. 컴파일 에러

    return 0;
}

