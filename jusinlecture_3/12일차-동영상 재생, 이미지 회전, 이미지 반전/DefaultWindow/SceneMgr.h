#pragma once

#include "Logo.h"
#include "MyMenu.h"
#include "MyEdit.h"
#include "Stage.h"


class CSceneMgr
{
public:
	enum SCENEID { SC_LOGO, SC_MENU, SC_EDIT, SC_STAGE, SC_END };

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

public:
	static CSceneMgr*		Get_Instance()
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
	static CSceneMgr*	m_pInstance;
	CScene*				m_pScene;

	SCENEID				m_ePreScene;
	SCENEID				m_eCurScene;

};

// state 패턴(상태 패턴) : FSM(유한 상태 기계 : 자신이 취할 수 있는 유한한 개수의 상태를 가짐)을 기반으로 하는 객체 상태를 표현하는 패턴, 오직 하나의 상태만을 취하도록 만드는 패턴
