#include "stdafx.h"
#include "KJW_Scene.h"
#include "KJW_LineMgr.h"
#include "KJW_Player.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "ScrollMgr.h"
#include "KJW_BossMonster.h"


CKJW_Scene::CKJW_Scene()
{
}

CKJW_Scene::~CKJW_Scene()
{
	Release();
}

void CKJW_Scene::Initialize()
{
	KJW_LINE.Initialize();
	BMP.Insert_Bmp(L"../Image/KJW/KJW_Ground.bmp", L"Ground");
	m_hGroundDC = BMP.Find_Img(L"Ground");

	BMP.Insert_Bmp(L"../Image/KJW/Player_LEFT.bmp", L"Player_LEFT");
	BMP.Insert_Bmp(L"../Image/KJW/Player_RIGHT.bmp", L"Player_RIGHT");

	BMP.Insert_Bmp(L"../Image/KJW/PLAYER_BULLET_LEFT.bmp", L"Player_Bullet_LEFT");
	BMP.Insert_Bmp(L"../Image/KJW/PLAYER_BULLET_RIGHT.bmp", L"Player_Bullet_RIGHT");
	BMP.Insert_Bmp(L"../Image/KJW/EFFECT_BULLET.bmp", L"Player_Bullet_EFFECT");

	BMP.Insert_Bmp(L"../Image/KJW/BOSS1.bmp", L"Boss");
	BMP.Insert_Bmp(L"../Image/KJW/BOSS1_DAMAGED.bmp", L"Boss_DAMAGED");
	BMP.Insert_Bmp(L"../Image/KJW/BOSS1_DAMAGED1.bmp", L"Boss_DEAD");

}

void CKJW_Scene::Start()
{
	m_pPlayer = CAbstractFactory<CKJW_Player>::Create();
	OBJ.Add_Object(OBJ_PLAYER, m_pPlayer);
	m_pBoss = CAbstractFactory<CKJW_BossMonster>::Create();
	OBJ.Add_Object(OBJ_MONSTER, m_pBoss);
	m_pBoss->Set_Target(m_pPlayer);
}

int CKJW_Scene::Update()
{
	return 0;
}

void CKJW_Scene::Late_Update()
{
	SCROLL.Scroll_Lock(MAPCX,MAPCY);
}
 
void CKJW_Scene::Render(HDC hDC)
{
	
	int	iScrollX = SCROLL.Get_ScrollX();
	int	iScrollY = SCROLL.Get_ScrollY();
	BitBlt(hDC, iScrollX, iScrollY, MAPCX, MAPCY, m_hGroundDC, 0, 0, SRCCOPY);
	KJW_LINE.Render(hDC);
}

void CKJW_Scene::Release()
{
}

