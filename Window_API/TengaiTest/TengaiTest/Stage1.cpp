#include "Stage1.h"
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
#include "PowerItem.h"
#include "BombItem.h"
#include "GreenBoss.h"
#include "BladeMonster.h"
#include "SpinningMonster.h"
#include "MonsterSpawnMgr.h"
CStage1::CStage1(): m_iScrollXSpeed(3),m_iScrollX(0),SceneEnd(false)
{
}

CStage1::~CStage1()
{
    Release();

}

void CStage1::Initialize()
{
    CMonsterSpawnMgr::Get_Instance()->Initialize();
    SoundMgr->PlayBGM(L"03_Sky_dance.ogg",0.2f);
    ObjMgr->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
    CUI* pPlayerHeadUI = CAbstractFactory<CPlayerHeadUI>::Create_UI(ObjMgr->Get_Player_Pointer()->Get_Info().fX,ObjMgr->Get_Player_Pointer()->Get_Info().fY-32.f,ObjMgr->Get_Player_Pointer());
    pPlayerHeadUI->Set_FrameKey(L"PowerUp");
    UIMgr->Add_UI(UI_PLAYER_HEAD_MASSAGE, pPlayerHeadUI);
    CUI* pPlayerLifeUI = CAbstractFactory<CPlayerLife>::Create_UI(100.f,30.f, ObjMgr->Get_Player_Pointer());
    pPlayerLifeUI->Set_FrameKey(L"MikoLife");
    UIMgr->Add_UI(UI_PLAYER_LIFE,pPlayerLifeUI);
    CUI* pPlayerBombUI = CAbstractFactory<CPlayerBombCount>::Create_UI(100.f,60.f, ObjMgr->Get_Player_Pointer());
    pPlayerBombUI->Set_FrameKey(L"BombCount");
    UIMgr->Add_UI(UI_PLAYER_BOMB, pPlayerBombUI);
    //ObjMgr->Add_Object(OBJ_BOSSMONSTER,CAbstractFactory<CGreenBoss>::Create());
    //ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create());
    //ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CSpinningMonster>::Create());
    ObjMgr->Add_Object(OBJ_ITEM,CAbstractFactory<CPowerItem>::Create());
    ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create());

    BmpMgr->Insert_Bmp(L"../ResourceImage/Map/forest.bmp", L"forest");
}

int CStage1::Update()
{
    CObjMgr::Get_Instance()->Update();
    if (ObjMgr->Check_ID_Empty(OBJ_PLAYER))
    {
        UIMgr->Delete_ID(UI_PLAYER_HEAD_MASSAGE);
        UIMgr->Delete_ID(UI_PLAYER_LIFE);
        UIMgr->Delete_ID(UI_PLAYER_BOMB);
        if (ObjMgr->Get_Player_DeadTime() + m_dwNextStageStartDelay < GetTickCount())
        {
            ObjMgr->Delete_All();
            SceneMgr->Scene_Change(CSceneMgr::SC_GAMEOVER);
        }
    }
    UIMgr->Update();
    if (MonsterSpawnMgr->Get_BossMonsterDead())
    {
        if(MonsterSpawnMgr->Get_BossMonsterDeadTime()+m_dwNextStageStartDelay<GetTickCount())
            SceneMgr->Scene_Change(CSceneMgr::SC_STAGE_2);
    }
    MonsterSpawnMgr->Update();
    return 0;
}

void CStage1::Late_Update()
{
    m_iScrollX -= m_iScrollXSpeed;
    if (WINCX - 3520 > m_iScrollX)
        m_iScrollX = 0;
    CObjMgr::Get_Instance()->Late_Update();
    UIMgr->Late_Update();
    MonsterSpawnMgr->Late_Update();
}

void CStage1::Render(HDC hDC)
{
    HDC hGroundDC = CBmpMgr::Get_Instance()->Find_Img(L"forest");

    //int	iScrollX = (int)ScrollMgr->Get_ScrollX();
    int	iScrollY = (int)ScrollMgr->Get_ScrollY();
    BitBlt(hDC, m_iScrollX, iScrollY, 3520, 720, hGroundDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);
    UIMgr->Render(hDC);

}

void CStage1::Release()
{
    SoundMgr->StopAll();
    //ObjMgr->Delete_ID(OBJ_PLAYER);
    ObjMgr->Delete_ID(OBJ_PET);
    //UIMgr->Delete_ID(UI_PLAYER_BOMB);
    //UIMgr->Delete_ID(UI_PLAYER_LIFE);
    //UIMgr->Delete_ID(UI_PLAYER_HEAD_MASSAGE);
    ObjMgr->Delete_ID(OBJ_MONSTER);
    ObjMgr->Delete_ID(OBJ_PLAYERBOMB);
    ObjMgr->Delete_ID(OBJ_EFFECT);
    CMonsterSpawnMgr::Destroy_Instance();
}
