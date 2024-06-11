#pragma once
#include "stdafx.h"
class CSG1MonsterSpawnMgr
{
public:
	CSG1MonsterSpawnMgr();
	~CSG1MonsterSpawnMgr();
public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Release();
	void		KillCountUp() { ++m_iMonsterKillCount; }
	void		Set_BossMonsterDead() { m_BossMonsterDead = true; m_dwBossDeadSaveTime = GetTickCount(); }
	bool		Get_BossMonsterDead() { return m_BossMonsterDead; }
	int			Get_BossMonsterDeadTime() { return m_dwBossDeadSaveTime; }
	/*void		Set_Stage2ClearTime() { m_dwStage2ClearSaveTime = GetTickCount(); }
	DWORD		Get_Stage2ClearTime() { return m_dwStage2ClearSaveTime; }*/
public:
	static CSG1MonsterSpawnMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CSG1MonsterSpawnMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
private:
	static CSG1MonsterSpawnMgr* m_pInstance;

	DWORD m_LimitSpawnTime = 2000;
	DWORD m_dwSpawnSmallMonsterTime = GetTickCount();
	//DWORD m_dwStage2ClearSaveTime;
	DWORD m_dwBossDeadSaveTime;

	int m_iMaxSpawnMonster = 3;
	float spawnX = 816.f;
	int m_iMonsterKillCount;
	bool m_BossMonsterSpawn;
	bool m_BossMonsterDead;
	//bool m_bstageend;
};

#define SG1MonsterSpawnMgr CSG1MonsterSpawnMgr::Get_Instance()
