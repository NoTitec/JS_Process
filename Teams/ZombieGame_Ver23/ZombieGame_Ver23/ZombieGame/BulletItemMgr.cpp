#include "pch.h"
#include "BulletItem.h"
#include "BulletItemMgr.h"
#include "AbstractFactory.h"

BULLET_TYPE CBulletItemMgr::m_eBulletType = BULLET_TYPE::BULLET_END;
DWORD CBulletItemMgr::m_dwCreateItemTime = GetTickCount();
CObj* CBulletItemMgr::m_pTarget = nullptr;
DWORD CBulletItemMgr::m_bulletItemLimitSpawnTimes[BULLET_TYPE::BULLET_END] = { 0, };

void CBulletItemMgr::Initialize()
{
	m_bulletItemLimitSpawnTimes[BULLET_TYPE::NORMAL_BULLET] = 5000;
	m_bulletItemLimitSpawnTimes[BULLET_TYPE::SHOTGUN_BULLET] = 5000;
	m_bulletItemLimitSpawnTimes[BULLET_TYPE::GRENADE_BULLET] = 8000;
}

void CBulletItemMgr::Spawn(list<CObj*>* _pBulletItemList, CObj* _pTarget)
{
	if (BULLET_TYPE::BULLET_END != m_eBulletType)
	{
		if (m_dwCreateItemTime + m_bulletItemLimitSpawnTimes[m_eBulletType] < GetTickCount())
		{
			int iRandX = 250 + rand() % (WINCX - 250);
			int iRandY = 150 + rand() % (WINCY - 150);

			_pBulletItemList->push_back(CAbstractFactory<CBulletItem>::Create(iRandX, iRandY, m_eBulletType));
			static_cast<CBulletItem*>(_pBulletItemList->back())->Set_Target(_pTarget);
			m_eBulletType = BULLET_TYPE::BULLET_END;
		}
	}
	else
	{
		BULLET_TYPE iSelectedItemIdx = (BULLET_TYPE)(rand() % BULLET_TYPE::BULLET_END);
		m_eBulletType = iSelectedItemIdx;
		m_dwCreateItemTime = GetTickCount();
	}
}
