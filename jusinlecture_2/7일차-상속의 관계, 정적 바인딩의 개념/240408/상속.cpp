#include "stdafx.h"

class CObj2
{
public:
	void		Render_Obj(){	cout << "obj" << endl;	}
};

class CPlayer2 : public CObj2
{
public:
	void		Render_Player() { cout << "Player" << endl; }
};

class CThief : public CPlayer2
{
public:
	void		Render_Thief() { cout << "Thief" << endl; }
};

int main()
{
	// 상속의 조건

	// 1. is-a 관계
	// 2. has-a 관계

	// 객체 포인터의 권한

	// CThief*		pThief = new CObj2;

	// CThief*		pThief  = new CThief;
	// CObj2*		pObj    = pThief;
	// CPlayer2*	pPlayer = pThief;
	// 
	// pPlayer->Render_Obj();
	// pPlayer->Render_Player();
	// pPlayer->Render_Thief();
	
	// 1. obj만		- 5, 0
	// 2. player만  - 0, 3
	// 3. thief만   - 1,0
	// 4. obj, player 둘 다 - 0, 13
	// 5. obj. thief 둘 다  - 0, 0
	// 6. player, thief 둘 다 - 0, 0
	// 7. 모두 다 호출 가능 - 11, 1
	// 8. 다 안 됨(컴파일 에러)- 2, 2


	return 0;
}