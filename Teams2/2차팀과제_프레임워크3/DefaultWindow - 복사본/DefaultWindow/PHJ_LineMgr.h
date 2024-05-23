#pragma once

#include "Line.h"
#include "Singleton.h"

class CPHJLineMgr : public CSingleton<CPHJLineMgr>
{
	friend CSingleton<CPHJLineMgr>;
private:
	CPHJLineMgr();
	virtual ~CPHJLineMgr();

public:
	void		Initialize();
	void		Render(HDC hDC);
	void		Release();
	void		Load_Line();
public:
	bool		Collision_Line(float fX, float fY, float* pY);

public:
	static CPHJLineMgr*		Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CPHJLineMgr;

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
	static CPHJLineMgr*	m_pInstance;
	list<CLine*>		m_LineList;
};

#define PHJLINE CPHJLineMgr::Get_Instance()