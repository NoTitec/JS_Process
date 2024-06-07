#include "MonsterSpawnMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "BladeMonster.h"


CMonsterSpawnMgr* CMonsterSpawnMgr::m_pInstance = nullptr;

CMonsterSpawnMgr::CMonsterSpawnMgr()
{
}

CMonsterSpawnMgr::~CMonsterSpawnMgr()
{
	Release();
}

void CMonsterSpawnMgr::Initialize()
{
}

void CMonsterSpawnMgr::Update()
{
	list<CObj*> monsterList = ObjMgr->Get_All_List(OBJ_ID::OBJ_MONSTER);
	int iMonsterSize = monsterList.size();


	if (m_dwSpawnSmallMonsterTime + m_LimitSpawnTime < GetTickCount())
	{
		if (iMonsterSize <= m_iMaxSpawnMonster)
		{
			ObjMgr->Add_Object(OBJ_ID::OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create(spawnArea.x, spawnArea.y));
		}
		m_dwSpawnSmallMonsterTime = GetTickCount();
	}


}

void CMonsterSpawnMgr::Late_Update()
{
}

void CMonsterSpawnMgr::Release()
{
}
