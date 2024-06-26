#include "stdafx.h"
#include "SunScene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SunPlayer.h"
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
}

int CSunScene::Update()
{
    OBJMGR->Update();

    return 0;
}

void CSunScene::Late_Update()
{
    OBJMGR->Late_Update();

}

void CSunScene::Render(HDC hDC)
{
    OBJMGR->Render(hDC);

}

void CSunScene::Release()
{
    OBJMGR->Delete_ID(OBJ_PLAYER);
    //OBJMGR->Delete_ID(OBJ_MONSTER);

}
