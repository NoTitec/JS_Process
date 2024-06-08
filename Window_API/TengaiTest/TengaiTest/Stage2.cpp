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
#include "Player.h"
#include "PowerItem.h"
#include "BombItem.h"
#include "GreenBoss.h"
#include "BladeMonster.h"
#include "MonsterSpawnMgr.h"
CStage2::CStage2()
{
}

CStage2::~CStage2()
{
    Release();
}

void CStage2::Initialize()
{
    CMonsterSpawnMgr::Get_Instance()->Initialize();
    SoundMgr->PlayBGM(L"08_Tall_cedar.ogg", 0.2f);
    ObjMgr->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
    CUI* pPlayerHeadUI = CAbstractFactory<CPlayerHeadUI>::Create_UI(ObjMgr->Get_Player_Pointer()->Get_Info().fX, ObjMgr->Get_Player_Pointer()->Get_Info().fY - 32.f, ObjMgr->Get_Player_Pointer());
    pPlayerHeadUI->Set_FrameKey(L"PowerUp");
    UIMgr->Add_UI(UI_PLAYER_HEAD_MASSAGE, pPlayerHeadUI);
    CUI* pPlayerLifeUI = CAbstractFactory<CPlayerLife>::Create_UI(100.f, 30.f, ObjMgr->Get_Player_Pointer());
    pPlayerLifeUI->Set_FrameKey(L"MikoLife");
    UIMgr->Add_UI(UI_PLAYER_LIFE, pPlayerLifeUI);
    CUI* pPlayerBombUI = CAbstractFactory<CPlayerBombCount>::Create_UI(100.f, 60.f, ObjMgr->Get_Player_Pointer());
    pPlayerBombUI->Set_FrameKey(L"BombCount");
    UIMgr->Add_UI(UI_PLAYER_BOMB, pPlayerBombUI);
    //ObjMgr->Add_Object(OBJ_BOSSMONSTER,CAbstractFactory<CGreenBoss>::Create());
    //ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create());
    ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create());
    ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create());

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
    }
    UIMgr->Update();
    MonsterSpawnMgr->Update();
    return 0;
}

void CStage2::Late_Update()
{
    CObjMgr::Get_Instance()->Late_Update();
    UIMgr->Late_Update();
    MonsterSpawnMgr->Late_Update();
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
    CMonsterSpawnMgr::Destroy_Instance();
}
