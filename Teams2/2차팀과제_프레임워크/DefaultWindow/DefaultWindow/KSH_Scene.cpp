#include "stdafx.h"
#include "SceneMgr.h"
#include "KSH_Scene.h"
#include "CKSHPlayer.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
void CKSH_Scene::Initialize()
{
}

//오브젝트 씬에서 필요한거 여기서 담음
void CKSH_Scene::Start()
{
    OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CKSHPlayer>::Create());
}

//update, lateupdate, render 서 직접 하는건 자기꺼 LineMgr만 하고 나머진 Main서 돌아가는중
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
}

void CKSH_Scene::Release()
{
}
