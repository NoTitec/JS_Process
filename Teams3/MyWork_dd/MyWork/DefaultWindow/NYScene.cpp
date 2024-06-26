#include "stdafx.h"
#include "NYScene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "Shield.h"


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
    CPlayer* pP = static_cast<CPlayer*>(pPlayer);

    CObj* pShield = CAbstractFactory<CShield>::Create();
    OBJMGR->Add_Object(OBJ_SHIELD, pShield);
    CShield* pS = static_cast<CShield*>(pShield);
    pS->Set_Parent(pPlayer);
    pP->Set_Shield(pShield);
    
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
