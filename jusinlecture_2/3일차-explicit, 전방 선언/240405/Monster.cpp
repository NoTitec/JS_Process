#include "stdafx.h"
#include "Monster.h"
#include "Player.h"

CMonster::CMonster()
{
	//m_pPlayer = new CPlayer;
}

CMonster::~CMonster()
{
}

void CMonster::Draw()
{
	m_pPlayer = new CPlayer;

	m_pPlayer->Render();
}
