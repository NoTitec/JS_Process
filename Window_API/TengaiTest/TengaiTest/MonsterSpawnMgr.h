#pragma once

#include "stdafx.h"
class CMonsterSpawnMgr
{
private:
	CMonsterSpawnMgr();
	~CMonsterSpawnMgr();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Release();

public:
	static CMonsterSpawnMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CMonsterSpawnMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	//list<CUI*> m_UIList[UI_END];
	static CMonsterSpawnMgr* m_pInstance;

	DWORD m_LimitSpawnTime = 3000;
	DWORD m_dwSpawnSmallMonsterTime = GetTickCount();
	int m_iMaxSpawnMonster = 3;

	POINT spawnArea = { 900, 100 };
};

#define MonsterSpawnMgr CMonsterSpawnMgr::Get_Instance()

