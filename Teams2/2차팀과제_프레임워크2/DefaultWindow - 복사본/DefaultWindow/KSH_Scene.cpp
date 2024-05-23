#include "stdafx.h"
#include "KSH_Scene.h"
#include "SceneMgr.h"
#include "KSH_LineMgr.h"
#include "KSHPlayer.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"

void CKSH_Scene::Initialize()
{
    OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CKSHPlayer>::Create());
    KSH_LINE.Initialize();
    BMP.Insert_Bmp(L"../Image/KSH_Back.bmp", L"KSH_Ground");
}

void CKSH_Scene::Start()
{

}

int CKSH_Scene::Update()
{
    return (int)KSH_SCENE;

    //씬종료조건시 다음씬 전환
    if (g_dwTime > 999999999999999)
    {
        SCENE.Change_Scene(KJW_SCENE);
    }
}

void CKSH_Scene::Late_Update()
{
}

void CKSH_Scene::Render(HDC hDC)
{
    //HDC hMemDC = BMP.Find_Img(L"KSH_Back");
    HDC hGroundDC = BMP.Find_Img(L"KSH_Ground");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hGroundDC, 0, 0, SRCCOPY);

    KSH_LINE.Render(hDC);
   
}

void CKSH_Scene::Release()
{
}

