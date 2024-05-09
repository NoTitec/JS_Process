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
	//Cobj ��� Ŭ����������� ����Ʈ ������
	list<CObj*>		m_ObjList[OBJ_END];

	HDC			m_DC;
	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};

