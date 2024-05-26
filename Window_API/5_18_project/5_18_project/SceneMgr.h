#pragma once
#include "Define.h"
#include "Logo.h"
#include "Menu.h"
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
	//ÇöÀç¾À
	CScene* m_pScene;

	SCENEID				m_ePreScene;
	SCENEID				m_eCurScene;

};

