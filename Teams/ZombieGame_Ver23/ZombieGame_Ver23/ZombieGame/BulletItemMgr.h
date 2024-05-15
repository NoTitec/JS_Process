#pragma once

#include "Obj.h"
class CObj;
class CBulletItemMgr
{
public:
	static void Initialize();
	static void Spawn(list<CObj*>* _pBulletItemList, CObj* _pTarget);

private:
	static BULLET_TYPE m_eBulletType;
	static DWORD m_dwCreateItemTime;
	static CObj* m_pTarget;
	static DWORD m_bulletItemLimitSpawnTimes[BULLET_TYPE::BULLET_END];
};

