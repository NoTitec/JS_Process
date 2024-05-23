#include "stdafx.h"
#include "PHJ_Scene.h"
#include "PHJ_LineMgr.h"
#include "RenderMgr.h"
#include "PHJ_Player.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "ScrollMgr.h"

CPHJ_Scene::CPHJ_Scene()
{
}

CPHJ_Scene::~CPHJ_Scene()
{
	Release();
}

void CPHJ_Scene::Initialize()
{

}

void CPHJ_Scene::Start()
{
	m_bClear = false;
	m_dSpawntimer1 = GetTickCount();
	m_dSpawntimer2 = GetTickCount();
	m_bSpawner = true;
	CPHJLineMgr::Get_Instance()->Initialize();
	OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CPHJ_Player>::Create());
	OBJ.Add_Object(OBJ_MONSTER, CAbstractFactory<CPHJ_Boss>::Create());
}

int CPHJ_Scene::Update()
{
	if(m_bSpawner)
	{
		if (m_dSpawntimer1 + 3000 <= GetTickCount()) // 3초마다 몬스터 1 소환
		{
			m_dSpawntimer1 = GetTickCount();
			OBJ.Add_Object(OBJ_MONSTER, CAbstractFactory<CPHJ_Monster1>::Create());
		}
		if (m_dSpawntimer2 + 5000 <= GetTickCount()) // 5초마다 몬스터 2 소환
		{
			m_dSpawntimer2 = GetTickCount();
			OBJ.Add_Object(OBJ_MONSTER, CAbstractFactory<CPHJ_Monster2>::Create());
		}
	}
	return OBJ_NOEVENT;
}

void CPHJ_Scene::Late_Update()
{
	int iScrollX = (int)SCROLL.Get_ScrollX();
	if (iScrollX < -5000) // 보스 만날떄 쯤 되면 일반몹 스폰 X
		m_bSpawner = false;
	//COLLISON.Collision_Rect()
}

void CPHJ_Scene::Render(HDC hDC)
{
	CPHJLineMgr::Get_Instance()->Render(hDC);
}

void CPHJ_Scene::Release()
{
	CPHJLineMgr::Destroy_Instance();
}
