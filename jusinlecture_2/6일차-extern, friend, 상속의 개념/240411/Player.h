#pragma once

#include "Monster.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	// friend void CMonster::Print(CPlayer* pPlayer);
	// friend void CMonster::Draw(CPlayer* pPlayer);

	friend class CMonster;	// private 멤버 접근을 허용하는 문법

private:
	int		m_iHp;

};

