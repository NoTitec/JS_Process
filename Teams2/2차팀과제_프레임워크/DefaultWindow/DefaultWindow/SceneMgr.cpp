#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene1.h"

CSceneMgr::CSceneMgr()
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Initialize()
{
	m_vecScene.push_back(new CScene1);
	m_iCurScene = 0;
	m_vecScene[m_iCurScene]->Initialize();
}

void CSceneMgr::Update()
{
	m_vecScene[m_iCurScene]->Update();
}

void CSceneMgr::Late_Update()
{
	m_vecScene[m_iCurScene]->Late_Update();
}

void CSceneMgr::Render(HDC _hdc)
{
	m_vecScene[m_iCurScene]->Render(_hdc);
}

void CSceneMgr::Release()
{
	for (auto& scene : m_vecScene)
	{
		Safe_Delete(scene);
	}
	m_vecScene.clear();
}
