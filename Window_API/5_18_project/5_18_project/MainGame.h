#pragma once
#include "Obj.h"
#include "Define.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Player.h"
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		LateUpdate();
	void		Render();
	void		Release();

private:
	//list<CObj*> m_ObjList[OBJ_END];
	HDC			m_DC;

	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];
};

