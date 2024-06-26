#include "stdafx.h"
#include "SceneMGr.h"
#include "Scene.h"
#include "NYScene.h"
#include "SunScene.h"
CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
{

}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENE_ID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case CSceneMgr::SC_NY:
			m_pScene = new CNYScene;
			break;
		case CSceneMgr::SC_JUN:
			// m_pScene = new CMyMenu;
			break;
		case CSceneMgr::SC_SANG:
			// m_pScene = new CMyEdit;
			break;
		case CSceneMgr::SC_SUN:
			m_pScene = new CSunScene;
			break;
		case CSceneMgr::SC_END:
			break;
		default:
			break;
		}

		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
