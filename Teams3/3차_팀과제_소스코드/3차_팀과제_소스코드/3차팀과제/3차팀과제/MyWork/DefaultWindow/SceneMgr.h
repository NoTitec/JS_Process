#pragma once

#include "Define.h"

class CScene;

class CSceneMgr
{
	DECLARE_SINGLE(CSceneMgr)
	
public:
	enum SCENE_ID
	{
		SC_NY,
		SC_SUN,
		SC_JUN,
		SC_SANG,
		SC_END = 5,
	};

public:
	void		Scene_Change(SCENE_ID eScene);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

public:
	CScene* Get_Cur_Scene() { return m_pScene; }

private:
	CScene*		m_pScene = nullptr;
	SCENE_ID	m_ePreScene = SC_END;
	SCENE_ID	m_eCurScene = SC_NY;
};

