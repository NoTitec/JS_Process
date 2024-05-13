#include "pch.h"
#include "CZombieMgr.h"
#include "Zombie.h"
#include "AbstractFactory.h"

float CZombieMgr::m_fSpawnPoses[8][2] = {
	{ 0.f, 0.f }, { WINCX / 2.0f, 0.f }, { WINCX, 0.f },
	{ 0.f, 0.f }, { WINCX, WINCY / 2.0f },
	{ 0.f, WINCY }, { WINCX / 2.0f, WINCY }, { WINCX, WINCY }
};

DWORD CZombieMgr::m_dwCreateZombieTime = GetTickCount();

void CZombieMgr::Spawn(list<CObj*>* _pZombieList, CObj* _pTarget, int _iMaxSpawnNumber, int _iMaxSpawnTime, OBJ_ZOMBIE_TYPE _eZombieType)
{
	bool bValidSpwanTime = m_dwCreateZombieTime + _iMaxSpawnTime < GetTickCount();
	bool bValidZombieSize = _pZombieList->size() < _iMaxSpawnNumber;

	int iSelectedSpwanAreaIdx = rand() % 8;

	if (bValidSpwanTime && bValidZombieSize)
	{
		_pZombieList->push_back(CAbstractFactory<CZombie>::Create());
		_pZombieList->back()->Set_Type(_eZombieType);
		_pZombieList->back()->Initialize();
		_pZombieList->back()->Set_Pos(m_fSpawnPoses[iSelectedSpwanAreaIdx][0], m_fSpawnPoses[iSelectedSpwanAreaIdx][1]);
		static_cast<CZombie*>(_pZombieList->back())->TargetPos_Update(Vec2{ _pTarget->Get_Pos().fX, _pTarget->Get_Pos().fY });
		m_dwCreateZombieTime = GetTickCount();
	}
}
