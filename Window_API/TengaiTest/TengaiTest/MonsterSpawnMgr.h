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
	void		KillCountUp() { ++m_iMonsterKillCount; }
	void		Set_BossMonsterDead() { m_BossMonsterDead = true; }
	bool		Get_BossMonsterDead() { return m_BossMonsterDead; }
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
	static CMonsterSpawnMgr* m_pInstance;

	DWORD m_LimitSpawnTime = 2000;
	DWORD m_dwSpawnSmallMonsterTime = GetTickCount();
	int m_iMaxSpawnMonster = 4;
	float spawnX = 816.f;
	int m_iMonsterKillCount;
	bool m_BossMonsterSpawn;
	bool m_BossMonsterDead;
};

#define MonsterSpawnMgr CMonsterSpawnMgr::Get_Instance()

