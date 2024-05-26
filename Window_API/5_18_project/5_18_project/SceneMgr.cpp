#include "SceneMgr.h"


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
	//현재씬 원하는 씬으로 변경
	m_eCurScene = eScene;
	//이전씬이랑 다를때만
	if (m_ePreScene != m_eCurScene)
	{
		//지금씬 제거
		Safe_Delete(m_pScene);

		//현재씬에따라 그씬 성성해서 내씬 포인터에 담기
		switch (m_eCurScene)
		{
		case SC_LOGO:
			m_pScene = new CLogo;
			break;

		case SC_MENU:
			m_pScene = new CMenu;
			break;

		case SC_STAGE:
			m_pScene = new CStage;
			break;
		}
		//씬 초기화
		m_pScene->Initialize();
		//이전씬에 다음 씬체인지 호출때 비교위해 지금씬 담아두기
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
