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

	static CScene* Change_Active_Scene(int _iSceneIdx)
	{
		m_pActiveScene->Release();
		m_pActiveScene = m_scenes[_iSceneIdx];
		m_pActiveScene->Initialize();
		return m_pActiveScene;
	}
private:
	static CScene* m_pActiveScene;
	static std::map<int, CScene*> m_scenes;
};

