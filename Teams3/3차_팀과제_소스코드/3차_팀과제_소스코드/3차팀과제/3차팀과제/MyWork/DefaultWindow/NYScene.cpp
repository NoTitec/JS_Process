#include "stdafx.h"
#include "NYScene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"

CNYScene::CNYScene()
{
}

CNYScene::~CNYScene()
{
    Release();
}

void CNYScene::Initialize()
{
    CObj* pPlayer = CAbstractFactory<CPlayer>::Create();
    OBJMGR->Add_Object(OBJ_PLAYER, pPlayer);
}

int CNYScene::Update()
{
    OBJMGR->Update();
    return 0;
}

void CNYScene::Late_Update()
{
    OBJMGR->Late_Update();
}

void CNYScene::Render(HDC hDC)
{
     OBJMGR->Render(hDC);
}

void CNYScene::Release()
{
    OBJMGR->Delete_ID(OBJ_PLAYER);
    OBJMGR->Delete_ID(OBJ_MONSTER);
 
}
