#include "pch.h"
#include "CZombieMgr.h"
#include "Zombie.h"
#include "AbstractFactory.h"

DWORD CZombieMgr::m_dwCreateZombieTime = GetTickCount();
void CZombieMgr::Create_Zombie(list<CObj*>* _pZombieList, CObj* _pTarget)
{
	float iSpwanArea[8][2] = {
		{ 0.f, 0.f },
		{ WINCX / 2.0f, 0.f },
		{ WINCX, 0.f },
		
		{ 0.0f, WINCY / 2.0f },
		{ WINCX , WINCY / 2.0f },
		
		{ 0.0f, WINCY },
		{ WINCX / 2.0f, WINCY },
		{ WINCX , WINCY }
	};

	if (m_dwCreateZombieTime + 750 < GetTickCount() && _pZombieList->size() < 10)
	{
		_pZombieList->push_back(CAbstractFactory<CZombie>::Create());
		int iSelectedSpawnAreaIdx = rand() % 8;
		_pZombieList->back()->Initialize();
		static_cast<CZombie*>(_pZombieList->back())->Set_Target(_pTarget);
		_pZombieList->back()->Set_Pos(iSpwanArea[iSelectedSpawnAreaIdx][0], iSpwanArea[iSelectedSpawnAreaIdx][1]);
		m_dwCreateZombieTime = GetTickCount();
	}
}
