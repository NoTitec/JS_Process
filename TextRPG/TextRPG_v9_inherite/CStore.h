#pragma once

class CPlayer;

class CStore
{
public:
	CStore();
	~CStore();

public:
	void Set_Player(CPlayer* pPlayer);

public:
	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_pPlayer;
};

