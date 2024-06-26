#include "stdafx.h"
#include "SunScene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SunPlayer.h"
#include "SunMonster.h"
#include "Shield.h"
CSunScene::CSunScene()
{
}

CSunScene::~CSunScene()
{
    Release();
}

void CSunScene::Initialize()
{
    CObj* pPlayer = CAbstractFactory<CSunPlayer>::Create();
    OBJMGR->Add_Object(OBJ_PLAYER, pPlayer);
    CSunPlayer* pP = static_cast<CSunPlayer*>(pPlayer);

    CObj* pMonster = CAbstractFactory<CSunMonster>::Create();
    OBJMGR->Add_Object(OBJ_MONSTER, pMonster);
    CSunMonster* pM = static_cast<CSunMonster*>(pMonster);
    pM->Set_Player(pPlayer);
    for (int i = 0; i < 10; ++i)
    {
        CObj* pMonster = CAbstractFactory<CSunMonster>::Create();
        OBJMGR->Add_Object(OBJ_MONSTER, pMonster);

    }
    /*CObj* pShield = CAbstractFactory<CShield>::Create();
    OBJMGR->Add_Object(OBJ_SHIELD, pShield);
    CShield* pS = static_cast<CShield*>(pShield);
    pS->Set_Parent(pPlayer);
    pP->Set_Shield(pShield);*/
}

int CSunScene::Update()
{
    OBJMGR->Update();
    return 0;
}

void CSunScene::Late_Update()
{
    OBJMGR->Late_Update();
    if (OBJMGR->Check_ID_Empty(OBJ_MONSTER))
    {
        //씬종료인데 내가 마지막씬인데??
    }
}

void CSunScene::Render(HDC hDC)
{
    OBJMGR->Render(hDC);
}

void CSunScene::Release()
{
    OBJMGR->Delete_ID(OBJ_PLAYER);
}
