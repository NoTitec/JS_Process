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
	// ����� ����

	// 1. is-a ����
	// 2. has-a ����

	// ��ü �������� ����

	// CThief*		pThief = new CObj2;

	// CThief*		pThief  = new CThief;
	// CObj2*		pObj    = pThief;
	// CPlayer2*	pPlayer = pThief;
	// 
	// pPlayer->Render_Obj();
	// pPlayer->Render_Player();
	// pPlayer->Render_Thief();
	
	// 1. obj��		- 5, 0
	// 2. player��  - 0, 3
	// 3. thief��   - 1,0
	// 4. obj, player �� �� - 0, 13
	// 5. obj. thief �� ��  - 0, 0
	// 6. player, thief �� �� - 0, 0
	// 7. ��� �� ȣ�� ���� - 11, 1
	// 8. �� �� ��(������ ����)- 2, 2


	return 0;
}