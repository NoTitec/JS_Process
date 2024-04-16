#include "stdafx.h"

class CObj1
{
public:
	virtual ~CObj1() {}

};

class CPlayer1 : public CObj1
{
public:
	void	Render() { cout << "player" << endl; }
};

class CMonster1
{
public:
	void	Draw() { cout << "Monster" << endl; }
};

int main()
{
	//CObj1*	pPlayer = new CPlayer1;	// up casting

	//((CPlayer1*)pPlayer)->Render();	// down casting

	//((CMonster1*)pPlayer)->Draw();

	//delete pPlayer;
	//pPlayer = nullptr;
	
	return 0;
}