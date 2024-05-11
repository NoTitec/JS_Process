#pragma once

#include "Obj.h"
class CZombieMgr
{
public:

public:
	static void Create_Zombie(list<CObj*>* _pZombieList, CObj* _pTarget);
private:
	static DWORD m_dwCreateZombieTime;
};

