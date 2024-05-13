#include "pch.h"
#include "SceneMgr.h"
#include "MainMenuScene.h"
#include "MainGameScene.h"
#include "GameOverScene.h"

CScene* CSceneMgr::m_pActiveScene = nullptr;
std::map<int, CScene*> CSceneMgr::m_scenes = {};

void CSceneMgr::Initialize()
{
	m_scenes.insert({ 0, new CMainMenuScene });
	m_scenes.insert({ 1, new CMainGameScene });
	m_scenes.insert({ 2, new CGameOverScene });

	// 진우형 일단 m_pActiveScene >> MainGameScene으로 바꿔둘게요.
	m_pActiveScene = m_scenes[1];
	m_pActiveScene->Initialize();
}

void CSceneMgr::Update()
{
	m_pActiveScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pActiveScene->Late_Update();
}

void CSceneMgr::Render(HDC _hdc)
{
	m_pActiveScene->Render(_hdc);
}

void CSceneMgr::Release()
{
	Safe_Delete<CScene*>(m_scenes[0]);
	Safe_Delete<CScene*>(m_scenes[1]);
	Safe_Delete<CScene*>(m_scenes[2]);
	m_scenes.clear();
}


