#pragma once
#include "stdafx.h"
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
	//플레이어 X,Y좌표를 인자로 받아서 플레이어의 Y좌표를 선의 y좌표로 설정해주는 함수
	bool Collision_Line(float fX, float fY,float* pY);
public:

	static CLineMgr* Get_Instance()
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

private:
	static CLineMgr* m_pInstance;
	list<CLine*>		m_LineList;
};

