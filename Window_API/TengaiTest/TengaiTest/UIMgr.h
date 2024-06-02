#pragma once
#include "UI.h"
class CUIMgr
{
private:
	CUIMgr();
	~CUIMgr();

public:
	void		Delete_ID(UI_ID eID);
	void		Add_UI(UI_ID eID, CUI* pUI);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

public:
	static CUIMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CUIMgr;

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
	list<CUI*> m_UIList[UI_END];
	static CUIMgr* m_pInstance;
};

#define UIMgr CUIMgr::Get_Instance()

