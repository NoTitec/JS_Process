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

	friend class CMonster;	// private ��� ������ ����ϴ� ����

private:
	int		m_iHp;

};

