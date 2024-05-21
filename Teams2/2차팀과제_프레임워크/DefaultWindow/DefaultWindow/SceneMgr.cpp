#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene1.h"
#include "HGH_Scene.h"
#include "KHR_Scene.h"
#include "KJW_Scene.h"
#include "KSH_Scene.h"
#include "PHJ_Scene.h"
CSceneMgr::CSceneMgr()
{
}

CSceneMgr::~CSceneMgr()
{
    Release();
}

void CSceneMgr::Initialize()
{
    //m_vecScene.push_back(new CHGH_Scene);
    //m_vecScene.push_back(new CKHR_Scene);
    //m_vecScene.push_back(new CKJW_Scene);
    //m_vecScene.push_back(new CKSH_Scene);
    //m_vecScene.push_back(new CPHJ_Scene);
    m_vecScene.push_back(new CKSH_Scene);
    for (auto scene : m_vecScene)
    {
        scene->Initialize();
    }
    //씬 열거체 [] 안에
    m_pCurScene = m_vecScene[0];
    m_vecScene[0]->Start();
}

void CSceneMgr::Update()
{
    m_pCurScene->Update();
}

void CSceneMgr::Late_Update()
{
    m_pCurScene->Late_Update();
}

void CSceneMgr::Render(HDC _hdc)
{
    m_pCurScene->Render(_hdc);
}

void CSceneMgr::Release()
{
    for (auto& scene : m_vecScene)
    {
        Safe_Delete(scene);
    }
    m_vecScene.clear();
}

void CSceneMgr::Change_Scene(SCENE_TYPE _eSceneType)
{
    OBJ.RemoveObjects();
    m_pCurScene = m_vecScene[_eSceneType];
    m_pCurScene->Start();

}