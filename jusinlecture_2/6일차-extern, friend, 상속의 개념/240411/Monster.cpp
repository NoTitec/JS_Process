#include "stdafx.h"
#include "Monster.h"

#include "Player.h"

CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Print(CPlayer* pPlayer)
{
	cout << pPlayer->m_iHp << endl;
}

void CMonster::Draw(CPlayer * pPlayer)
{
	cout << pPlayer->m_iHp << endl;
}
