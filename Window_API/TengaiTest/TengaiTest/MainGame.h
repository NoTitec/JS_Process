#pragma once
#include "stdafx.h"
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
#pragma region ����
	//CObj*		m_pPlayer;
	//list<CObj*>	m_BulletList;
#pragma endregion ����


	HDC			m_DC;
	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};


