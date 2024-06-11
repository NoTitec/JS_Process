#include "Stage2.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "UIMgr.h"
#include "PlayerHeadUI.h"
#include "PlayerLife.h"
#include "PlayerBombCount.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"
#include "Player.h"
#include "MikoPet.h"
#include "PowerItem.h"
#include "BombItem.h"
#include "GreenBoss.h"
#include "BladeMonster.h"
#include "Hemisphere.h"
//#include "MonsterSpawnMgr.h"
#include "SG1MonsterSpawnMgr.h"
CStage2::CStage2()
{
}

CStage2::~CStage2()
{
    Release();
}

void CStage2::Initialize()
{
    //ObjMgr->Add_Object(OBJ_BOSSMONSTER, CAbstractFactory<CHemisphere>::Create());

    ObjMgr->Get_Player_Pointer()->Initialize();
    //스테이지 2 용 스폰매니저로 교체필요
    CSG1MonsterSpawnMgr::Get_Instance()->Initialize();
    /*if (ObjMgr->Check_ID_Empty(OBJ_PET))
    {
        CObj* petpoint = ObjMgr->Get_Pet_Pointer();
        dynamic_cast<CMikoPet*>(petpoint)->Set_Level(CMikoPet::LEVEL_ZERO);
    }*/
    SoundMgr->PlayBGM(L"08_Tall_cedar.ogg", 0.2f);
    //ObjMgr->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
    //CUI* pPlayerHeadUI = CAbstractFactory<CPlayerHeadUI>::Create_UI(ObjMgr->Get_Player_Pointer()->Get_Info().fX, ObjMgr->Get_Player_Pointer()->Get_Info().fY - 32.f, ObjMgr->Get_Player_Pointer());
    //pPlayerHeadUI->Set_FrameKey(L"PowerUp");
    /*UIMgr->Add_UI(UI_PLAYER_HEAD_MASSAGE, pPlayerHeadUI);
    CUI* pPlayerLifeUI = CAbstractFactory<CPlayerLife>::Create_UI(100.f, 30.f, ObjMgr->Get_Player_Pointer());
    pPlayerLifeUI->Set_FrameKey(L"MikoLife");
    UIMgr->Add_UI(UI_PLAYER_LIFE, pPlayerLifeUI);
    CUI* pPlayerBombUI = CAbstractFactory<CPlayerBombCount>::Create_UI(100.f, 60.f, ObjMgr->Get_Player_Pointer());
    pPlayerBombUI->Set_FrameKey(L"BombCount");
    UIMgr->Add_UI(UI_PLAYER_BOMB, pPlayerBombUI);*/
    //ObjMgr->Add_Object(OBJ_BOSSMONSTER,CAbstractFactory<CGreenBoss>::Create());
    //ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create());
    //ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create());
    //ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create());

    BmpMgr->Insert_Bmp(L"../ResourceImage/Map/Sky.bmp", L"Sky");
}

int CStage2::Update()
{
    CObjMgr::Get_Instance()->Update();
    if (ObjMgr->Check_ID_Empty(OBJ_PLAYER))
    {
        UIMgr->Delete_ID(UI_PLAYER_HEAD_MASSAGE);
        UIMgr->Delete_ID(UI_PLAYER_LIFE);
        UIMgr->Delete_ID(UI_PLAYER_BOMB);
        if (ObjMgr->Get_Player_DeadTime() + 3000 < GetTickCount())
        {
            ObjMgr->Delete_All();
            SceneMgr->Scene_Change(CSceneMgr::SC_GAMEOVER);
        }
    }
    UIMgr->Update();
    if (SG1MonsterSpawnMgr->Get_BossMonsterDeadTime() + m_dwStageEndDelay < GetTickCount())
    {
        SceneMgr->Scene_Change(CSceneMgr::SC_LOGO);
    }
    SG1MonsterSpawnMgr->Update();
    return 0;
}

void CStage2::Late_Update()
{
    CObjMgr::Get_Instance()->Late_Update();
    UIMgr->Late_Update();
    SG1MonsterSpawnMgr->Late_Update();
}

void CStage2::Render(HDC hDC)
{
    HDC hGroundDC = CBmpMgr::Get_Instance()->Find_Img(L"Sky");

    //int	iScrollX = (int)ScrollMgr->Get_ScrollX();
    //int	iScrollY = (int)ScrollMgr->Get_ScrollY();
    BitBlt(hDC, 0, 0, 800,600, hGroundDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);
    UIMgr->Render(hDC);
}

void CStage2::Release()
{
    SoundMgr->StopAll();
    ObjMgr->Delete_All();
    /*ObjMgr->Delete_ID(OBJ_PLAYER);
    ObjMgr->Delete_ID(OBJ_PET);*/
    UIMgr->Delete_ID(UI_PLAYER_BOMB);
    UIMgr->Delete_ID(UI_PLAYER_LIFE);
    UIMgr->Delete_ID(UI_PLAYER_HEAD_MASSAGE);
    //ObjMgr->Delete_ID(OBJ_MONSTER);
    CSG1MonsterSpawnMgr::Destroy_Instance();
}
