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

//������Ʈ ������ �ʿ��Ѱ� ���⼭ ����
void CKSH_Scene::Start()
{
    OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CKSHPlayer>::Create());
}

//update, lateupdate, render �� ���� �ϴ°� �ڱⲨ LineMgr�� �ϰ� ������ Main�� ���ư�����
int CKSH_Scene::Update()
{
    return (int)KSH_SCENE;

    //���������ǽ� ������ ��ȯ
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
