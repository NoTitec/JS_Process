#pragma once


class CPlayer;
class CMonster;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	bool Initialize();
	void Update();
	int Battle(CPlayer* player, CMonster* monster);
	void Release();

private:
	CPlayer* m_Player;
};

