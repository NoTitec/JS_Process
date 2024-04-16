#pragma once

class CPlayer;
class CMonster;
class Character;

class CField
{
public:
	CField();
	~CField();

public:
	void Set_Player(Character* pPlayer);

public:
	void Initialize();
	void Update();
	void Release();

private:
	Character* m_pPlayer;
	CMonster* m_pMonster;
};

