#pragma once

#include "Obj.h"
class CZombieMgr
{
public:

public:
	static bool Is_Clear_Stage()
	{
		return m_iGoalZombiesNumber <= m_iDeathZombiesNumber;
	}

	static void Kill_Zombie()
	{
		++m_iDeathZombiesNumber;
	}

	static void Set_Goal_Zombies_Number(int _iGoalZombiesNumber)
	{
		m_iGoalZombiesNumber = _iGoalZombiesNumber;
	}

	static void Set_Light_Zombie_Limit_Number(int _iLightZombieLimitNumber) 
	{ 
		m_iSpawnLimitNumbers[OBJ_ZOMBIE_TYPE::OBJ_LIGHT_ZOMBIE] = _iLightZombieLimitNumber; 
	}
	
	static void Set_Middle_Zombie_Limit_Number(int _iMiddleZombieLimitNumber)
	{
		m_iSpawnLimitNumbers[OBJ_ZOMBIE_TYPE::OBJ_MIDDLE_ZOMBIE] = _iMiddleZombieLimitNumber;
	}

	static void Set_Heavy_Zombie_Limit_Number(int _iHeavyZombieLimitNumber)
	{
		m_iSpawnLimitNumbers[OBJ_ZOMBIE_TYPE::OBJ_HEAVY_ZOMBIE] = _iHeavyZombieLimitNumber;
	}

	static void Spawn(list<CObj*>* _pZombieList, CObj* _pTarget, int _iMaxSpawnTime, OBJ_ZOMBIE_TYPE _eZombieType, bool _bBossStage);

	static void Clear_All_Zombies(list<CObj*>* _pZombieList);

	static void Refresh_Current_Spawn_Numbers(list<CObj*>* _pZombieList);
public:
	static bool m_bNormalStage;

	static DWORD m_dwCreateZombieTime;
	static float m_fSpawnPoses[8][2];

	static int m_iSpawnLimitNumbers[OBJ_ZOMBIE_END];
	static int m_iSpawnNumbers[OBJ_ZOMBIE_END];

	static int m_iGoalZombiesNumber;
	static int m_iTotalSpawnNumber;
	static int m_iDeathZombiesNumber;
};

