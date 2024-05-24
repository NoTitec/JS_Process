#include "stdafx.h"
#include "KSH_Scene.h"
#include "SceneMgr.h"
#include "KSH_LineMgr.h"
#include "KSHPlayer.h"
#include "KSH_BossMonster.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

void CKSH_Scene::Initialize()
{
	OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CKSHPlayer>::Create());
    OBJ.Add_Object(OBJ_MONSTER, CAbstractFactory<CKSH_BossMonster>::Create(700.f,300.f));
	KSH_LINE.Initialize();
	BMP.Insert_Bmp(L"../Image/KSH_Ground.bmp", L"KSH_Ground");
    BMP.Insert_Bmp(L"../Image/Monster.bmp", L"KSH_BossMonster");


}

void CKSH_Scene::Start()
{
}

int CKSH_Scene::Update()
{

    //씬종료조건시 다음씬 전환
    if (OBJ.Check_ID_Empty(OBJ_MONSTER))
    {
        SCENE.Change_Scene(KJW_SCENE);
        return (int)KJW_SCENE;
    }


    return (int)KSH_SCENE;

    

}

void CKSH_Scene::Late_Update()
{
    SCROLL.Scroll_Lock(1920,600);
}

void CKSH_Scene::Render(HDC hDC)
{
    //HDC hMemDC = BMP.Find_Img(L"KSH_Back");
    int iScrollX = (int)SCROLL.Get_ScrollX();
    HDC hGroundDC = BMP.Find_Img(L"KSH_Ground");

    BitBlt(hDC, iScrollX, 0, 1920, 1280, hGroundDC, 0, 0, SRCCOPY);

    KSH_LINE.Render(hDC);

}

void CKSH_Scene::Release()
{
}

