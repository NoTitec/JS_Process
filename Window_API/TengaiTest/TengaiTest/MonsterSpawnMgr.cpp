#include "MonsterSpawnMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "BladeMonster.h"
#include "GreenBoss.h"

CMonsterSpawnMgr* CMonsterSpawnMgr::m_pInstance = nullptr;

CMonsterSpawnMgr::CMonsterSpawnMgr() :m_iMonsterKillCount(0),m_BossMonsterSpawn(true),m_BossMonsterDead(false)
{
}

CMonsterSpawnMgr::~CMonsterSpawnMgr()
{
	Release();
}

void CMonsterSpawnMgr::Initialize()
{
	m_iMonsterKillCount = 0;
}

void CMonsterSpawnMgr::Update()
{
	list<CObj*> monsterList = ObjMgr->Get_ID_List(OBJ_ID::OBJ_MONSTER);
	int iMonsterSize = monsterList.size();


	if (m_dwSpawnSmallMonsterTime + m_LimitSpawnTime < GetTickCount())
	{
		if (iMonsterSize <= m_iMaxSpawnMonster&&(!m_BossMonsterDead))
		{
			float randY = 100.f + rand() % 400;
			ObjMgr->Add_Object(OBJ_ID::OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create(spawnX,randY));
		}
		m_dwSpawnSmallMonsterTime = GetTickCount();
	}
	if (m_iMonsterKillCount >= 20)
	{
		if (m_BossMonsterSpawn)
		{
			ObjMgr->Add_Object(OBJ_BOSSMONSTER, CAbstractFactory<CGreenBoss>::Create());
			m_BossMonsterSpawn = false;
		}
	}

}

void CMonsterSpawnMgr::Late_Update()
{
}

void CMonsterSpawnMgr::Release()
{
}
