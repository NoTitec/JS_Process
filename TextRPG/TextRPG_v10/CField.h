#pragma once
#include "CPlayer.h"
class CField
{
public:
	CField();
	~CField();

public:
	void Set_Player(CBase* pPlayer);
	int Fight();

public:
	void Initialize();
	void Update();
	void Release();

private:
	CBase* m_pPlayer;
	CBase* m_pMonster;
};

