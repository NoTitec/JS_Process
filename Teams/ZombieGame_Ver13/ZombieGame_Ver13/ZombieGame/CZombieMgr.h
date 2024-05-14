#pragma once

#include "Obj.h"
class CZombieMgr
{
public:

public:
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

	static void Spawn(list<CObj*>* _pZombieList, CObj* _pTarget, int _iMaxSpawnTime, OBJ_ZOMBIE_TYPE _eZombieType);

	static void Refresh_Current_Spawn_Numbers(list<CObj*>* _pZombieList);
private:
	static DWORD m_dwCreateZombieTime;
	static float m_fSpawnPoses[8][2];

	static int m_iSpawnLimitNumbers[OBJ_ZOMBIE_END];
	static int m_iSpawnNumbers[OBJ_ZOMBIE_END];
};

