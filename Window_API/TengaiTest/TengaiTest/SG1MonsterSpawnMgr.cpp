#include "SG1MonsterSpawnMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SpinningMonster.h"
#include "SceneMgr.h"
#include "Hemisphere.h"
CSG1MonsterSpawnMgr* CSG1MonsterSpawnMgr::m_pInstance = nullptr;

CSG1MonsterSpawnMgr::CSG1MonsterSpawnMgr() :m_iMonsterKillCount(0), m_BossMonsterSpawn(true), m_BossMonsterDead(false)
{
}

CSG1MonsterSpawnMgr::~CSG1MonsterSpawnMgr()
{
	Release();
}

void CSG1MonsterSpawnMgr::Initialize()
{
	m_iMonsterKillCount = 0;
	//m_bstageend = true;
}

void CSG1MonsterSpawnMgr::Update()
{
	list<CObj*> monsterList = ObjMgr->Get_ID_List(OBJ_ID::OBJ_MONSTER);
	int iMonsterSize = monsterList.size();


	if (m_dwSpawnSmallMonsterTime + m_LimitSpawnTime < GetTickCount())
	{
		if (iMonsterSize <= m_iMaxSpawnMonster && (!m_BossMonsterDead))
		{
			float randY = 100.f + rand() % 400;
			ObjMgr->Add_Object(OBJ_ID::OBJ_MONSTER, CAbstractFactory<CSpinningMonster>::Create(spawnX, randY));
		}
		m_dwSpawnSmallMonsterTime = GetTickCount();
	}
	if (m_iMonsterKillCount >=10)
	{
		/*Set_Stage2ClearTime();
		m_bstageend = false;*/
		if (m_BossMonsterSpawn)
		{
			if (SceneMgr->Get_SceneID() == CSceneMgr::SC_STAGE_2)
			{
				ObjMgr->Add_Object(OBJ_BOSSMONSTER, CAbstractFactory<CHemisphere>::Create());
				m_BossMonsterSpawn = false;
			}
		}
	}
	/*if (m_iMonsterKillCount >= 5)
	{
		if (m_BossMonsterSpawn)
		{
			ObjMgr->Add_Object(OBJ_BOSSMONSTER, CAbstractFactory<CGreenBoss>::Create());
			m_BossMonsterSpawn = false;
		}
	}*/
}

void CSG1MonsterSpawnMgr::Late_Update()
{
}

void CSG1MonsterSpawnMgr::Release()
{
}
