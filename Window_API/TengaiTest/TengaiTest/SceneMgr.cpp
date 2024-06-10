#include "SceneMgr.h"
#include "stdafx.h"
#include "SoundMgr.h"
#include "Logo.h"
#include "Select.h"
#include "Stage1.h"
#include "Stage2.h"
#include "GameOverScene.h"
CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr() : m_pScene(nullptr), m_ePreScene(SC_END), m_eCurScene(SC_LOGO)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();

}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);
		switch (m_eCurScene)
		{
		case SC_LOGO:
			m_pScene = new CLogo;
			break;
		
		case SC_MENU:
			m_pScene = new CSelect;
			break;
			
		case SC_GAMEOVER:
			m_pScene = new CGameOverScene;
			break;
			
		case SC_STAGE_1:
			m_pScene = new CStage1;
			break;
		case SC_STAGE_2:
			m_pScene = new CStage2;
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
