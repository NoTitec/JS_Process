#include "pch.h"
#include "SceneMgr.h"
#include "MainMenuScene.h"
#include "MainGameScene.h"
#include "GameOverScene.h"
#include "BossGameScene.h"

SCENE_TYPE CSceneMgr::m_iCurrentSceneIdx = SCENE_TYPE::SCENE_TYPE_END;
SCENE_TYPE CSceneMgr::m_iBeforeSceneIdx = SCENE_TYPE::SCENE_TYPE_END;
CScene* CSceneMgr::m_pActiveScene = nullptr;
std::map<SCENE_TYPE, CScene*> CSceneMgr::m_scenes = {};

void CSceneMgr::Initialize()
{
	m_scenes.insert({ SCENE_TYPE::MAIN_MENU_SCENE, new CMainMenuScene });
	m_scenes.insert({ SCENE_TYPE::MAIN_GAME_SCENE, new CMainGameScene });
	m_scenes.insert({ SCENE_TYPE::GAME_OVER_SCENE, new CGameOverScene });
	m_scenes.insert({ SCENE_TYPE::BOSS_GAME_SCENE, new CBossGameScene });

	// 진우형 일단 m_pActiveScene >> MainGameScene으로 바꿔둘게요.
	m_iCurrentSceneIdx = SCENE_TYPE::BOSS_GAME_SCENE;
	m_iBeforeSceneIdx = m_iCurrentSceneIdx;
	m_pActiveScene = m_scenes[m_iCurrentSceneIdx];
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
	Safe_Delete<CScene*>(m_scenes[SCENE_TYPE::MAIN_MENU_SCENE]);
	Safe_Delete<CScene*>(m_scenes[SCENE_TYPE::MAIN_GAME_SCENE]);
	Safe_Delete<CScene*>(m_scenes[SCENE_TYPE::GAME_OVER_SCENE]);
	Safe_Delete<CScene*>(m_scenes[SCENE_TYPE::BOSS_GAME_SCENE]);
	m_scenes.clear();
}


