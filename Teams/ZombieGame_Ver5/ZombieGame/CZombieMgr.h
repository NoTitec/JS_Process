#pragma once

#include "Obj.h"
class CZombieMgr
{
public:

public:
	static void Spawn(list<CObj*>* _pZombieList, CObj* _pTarget, int _iMaxSpawnNumber, int _iMaxSpawnTime, OBJ_ZOMBIE_TYPE _eZombieType);
private:
	static DWORD m_dwCreateZombieTime;
	static float m_fSpawnPoses[8][2];
};

