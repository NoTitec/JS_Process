#include "stdafx.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	CPlayer		Player;

	CMonster	Monster;

	Monster.Print(&Player);
	Monster.Draw(&Player);

	return 0;
}