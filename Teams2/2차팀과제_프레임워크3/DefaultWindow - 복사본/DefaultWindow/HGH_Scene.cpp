#include "stdafx.h"
#include "HGH_Scene.h"
#include "FactoryMgr.h"
#include "ObjMgr.h"
#include "Object.h"
#include "PushUpLineColliderComponent.h"
#include "HGH_CollisionMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "MyBmp.h"
#include "RenderMgr.h"

CHGH_Scene::CHGH_Scene()
{
}
CHGH_Scene::~CHGH_Scene()
{
    Release();
}
void CHGH_Scene::Initialize()
{
    FACTORY.Initialize();
    m_pLineEditor = new HGH_LineEditor;
    BMP.Insert_Bmp(L"../Image/HGH_Background.bmp", L"HGH_Background");
}

void CHGH_Scene::Start()
{
    CObject* pPlayer = BUILD_OBJECT(ObjectType::Player);
    OBJ.Add_Object(OBJ_PLAYER, pPlayer);
    RENDER.Set_Target(pPlayer);
    RENDER.Set_Region({ 0,0 }, { 1890, 941});


    CObject* pLine;
    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {0,800},{1600,800} });
    OBJ.Add_Object(OBJ_LINE, pLine);

    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {800,1100},{800,100} });
    OBJ.Add_Object(OBJ_LINE, pLine);

    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {1600,1100},{1600,100} });
    OBJ.Add_Object(OBJ_LINE, pLine);
    /*pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {300,500},{500,300} });
    OBJ.Add_Object(OBJ_LINE, pLine);

    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {500,300},{1000,300} });
    OBJ.Add_Object(OBJ_LINE, pLine);

    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {500,300},{1000,300} });
    OBJ.Add_Object(OBJ_LINE, pLine);

    pLine = BUILD_OBJECT(ObjectType::Line);
    static_cast<CLineColliderComponent*>(pLine->Get_Component(ComponentType::PushUpLineCollider))->Set_Line({ {100,300},{300,300} });
    OBJ.Add_Object(OBJ_LINE, pLine);*/
}


int CHGH_Scene::Update()
{
    m_pLineEditor->Update();
    return 0;
}

void CHGH_Scene::Late_Update()
{
    HGH_COLLISION.Late_Update();
    RENDER.Late_Update();
}

void CHGH_Scene::Render(HDC hDC)
{

    RENDER.DrawBackground(BMP.Find_Img(L"HGH_Background"), { 0,0,1890,941 });
    //RENDER.DrawBMP(BMP.Find_Img(L"HGH_Background"), { 0,0,1890,941 }, { 0,0,1890,941 }, WHITENESS);
    //m_pLineEditor->Render();
}

void CHGH_Scene::Release()
{
    Safe_Delete(m_pLineEditor);
}


