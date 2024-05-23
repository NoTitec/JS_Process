#pragma once
#include <vector>
#include "Singleton.h"
#include "Scene.h"

class CSceneMgr : public CSingleton<CSceneMgr>
{
	friend CSingleton<CSceneMgr>;

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void      Initialize();
	void      Update();
	void      Late_Update();
	void      Render(HDC _hdc);
	void      Release();

	void      Change_Scene(SCENE_TYPE _eSceneType);

private:
	vector<CScene*> m_vecScene;
	CScene* m_pCurScene;
};

#define SCENE CSceneMgr::Get_Instance()