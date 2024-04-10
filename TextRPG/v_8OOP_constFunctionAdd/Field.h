#pragma once
class CMonster;
class CPlayer;

class CField
{
public:
	CField();
	~CField();

public:

	void Set_Player(CPlayer* pPlayer);
	//int Battle();

public:
	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_pPlayer;
	CMonster* m_Monster;
};

