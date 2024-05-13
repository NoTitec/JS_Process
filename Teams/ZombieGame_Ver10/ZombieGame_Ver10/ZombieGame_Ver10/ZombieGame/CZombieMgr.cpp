#include "pch.h"
#include "CZombieMgr.h"
#include "Zombie.h"
#include "AbstractFactory.h"


float CZombieMgr::m_fSpawnPoses[8][2] = {
	{ 0.f, 0.f }, { WINCX / 2.0f, 0.f }, { WINCX, 0.f },
	{ 0.f, 0.f }, { WINCX, WINCY / 2.0f },
	{ 0.f, WINCY }, { WINCX / 2.0f, WINCY }, { WINCX, WINCY }
};

int CZombieMgr::m_iSpawnLimitNumbers[OBJ_ZOMBIE_TYPE::OBJ_ZOMBIE_END] = { 0, };
//현재 필드에 소환되어있는 좀비 수들
int CZombieMgr::m_iSpawnNumbers[OBJ_ZOMBIE_TYPE::OBJ_ZOMBIE_END] = { 0, };

DWORD CZombieMgr::m_dwCreateZombieTime = GetTickCount();
void CZombieMgr::Spawn(list<CObj*>* _pZombieList, CObj* _pTarget, int _iMaxSpawnTime, OBJ_ZOMBIE_TYPE _eZombieType)
{
	bool bValidSpwanTime = m_dwCreateZombieTime + _iMaxSpawnTime < GetTickCount();
	bool bValidZombieSize = m_iSpawnLimitNumbers[_eZombieType] > m_iSpawnNumbers[_eZombieType];
	int iSelectedSpwanAreaIdx = rand() % 8;

	if (bValidSpwanTime && bValidZombieSize)
	{
		_pZombieList->push_back(CAbstractFactory<CZombie>::Create());
		_pZombieList->back()->Set_Type(_eZombieType);
		_pZombieList->back()->Initialize();
		_pZombieList->back()->Set_Pos(m_fSpawnPoses[iSelectedSpwanAreaIdx][0], m_fSpawnPoses[iSelectedSpwanAreaIdx][1]);
		++m_iSpawnNumbers[_eZombieType];

		static_cast<CZombie*>(_pZombieList->back())->TargetPos_Update(Vec2{ _pTarget->Get_Pos().fX, _pTarget->Get_Pos().fY });
		m_dwCreateZombieTime = GetTickCount();
	}
}
//프레임마다 필드에 소환되어있는 좀비들의 수를 갱신하는 함수
void CZombieMgr::Refresh_Current_Spawn_Numbers(list<CObj*>* _pZombieList)
{
	ZeroMemory(&m_iSpawnNumbers, sizeof(m_iSpawnNumbers));
	for (auto& pZombie : (*_pZombieList))
	{
		++m_iSpawnNumbers[pZombie->Get_type()];
	}
}
