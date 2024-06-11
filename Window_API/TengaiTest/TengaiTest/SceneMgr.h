#pragma once
#include "stdafx.h"
#include "Scene.h"
class CSceneMgr
{
public:
	enum SCENEID { SC_LOGO, SC_MENU,SC_Load, SC_STAGE_1,SC_STAGE_2,SC_GAMEOVER, SC_END };

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void	Scene_Change(SCENEID eScene);
	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();
	SCENEID		Get_SceneID() { return m_eCurScene; }
	SCENEID		Get_LoadCallerID() { return m_eLoadSceneCaller; }
	void		Set_LoadCallerID(SCENEID eID) { m_eLoadSceneCaller = eID; }
public:
	static CSceneMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CSceneMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CSceneMgr* m_pInstance;
	CScene* m_pScene;
	SCENEID				m_eLoadSceneCaller;
	SCENEID				m_ePreScene;
	SCENEID				m_eCurScene;

};

#define SceneMgr CSceneMgr::Get_Instance()