#pragma once

#include "Scene.h"

class CScene;
class CSceneMgr
{
public:
	static void Initialize();
	static void Update();
	static void Late_Update();
	static void Render(HDC _hdc);
	static void Release();

	static CScene* Change_Active_Scene(SCENE_TYPE _iSceneIdx)
	{
		m_iBeforeSceneIdx = m_iCurrentSceneIdx;
		m_pActiveScene->Release();
		m_pActiveScene = m_scenes[_iSceneIdx];
		m_pActiveScene->Initialize();
		m_iCurrentSceneIdx = _iSceneIdx;
		return m_pActiveScene;
	}
private:
	static SCENE_TYPE m_iCurrentSceneIdx;
	static SCENE_TYPE m_iBeforeSceneIdx;
	static CScene* m_pActiveScene;
	static std::map<SCENE_TYPE, CScene*> m_scenes;
};

