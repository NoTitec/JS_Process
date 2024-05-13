#pragma once
#include "stdafx.h"

class CObj;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	//Cobj 기반 클래스들저장용 리스트 포인터
	list<CObj*>		m_ObjList[OBJ_END];

	HDC			m_DC;
	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};

