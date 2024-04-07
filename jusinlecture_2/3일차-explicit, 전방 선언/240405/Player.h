#pragma once

#include "Monster.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	void	Render() { cout << "jusin" << endl; }
	void	Print()
	{
		m_Monster.Output();
	}

private:
	CMonster m_Monster;
};

