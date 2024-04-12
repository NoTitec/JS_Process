#pragma once

class CPlayer;
class CMonster
{
public:
	CMonster();
	~CMonster();

public:
	void	Print(CPlayer* pPlayer);
	void	Draw(CPlayer* pPlayer);
};

