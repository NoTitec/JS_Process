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
	//����� ���ϴ� ������ ����
	m_eCurScene = eScene;
	//�������̶� �ٸ�����
	if (m_ePreScene != m_eCurScene)
	{
		//���ݾ� ����
		Safe_Delete(m_pScene);

		//����������� �׾� �����ؼ� ���� �����Ϳ� ���
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
		//�� �ʱ�ȭ
		m_pScene->Initialize();
		//�������� ���� ��ü���� ȣ�⶧ ������ ���ݾ� ��Ƶα�
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
