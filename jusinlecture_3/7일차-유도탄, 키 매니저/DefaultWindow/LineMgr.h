#pragma once

#include "Line.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	void		Initialize();
	void		Render(HDC hDC);
	void		Release();

public:
	static CLineMgr*		Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CLineMgr;

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
	list<CLine*>* Get_LineList()
	{
		return &m_LineList;
		//return nullptr;
	}
private:
	static CLineMgr*	m_pInstance;
	 list<CLine*>		m_LineList;
};

