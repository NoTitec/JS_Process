#pragma once
#include "stdafx.h"
#include "Obj.h"

class CZombieManager
{
public:
	static void Create_Zombie(list<CObj*>* _pZombieList, CObj* _pTarget);
private:
	static DWORD m_dwCreateZombieTime;
};

