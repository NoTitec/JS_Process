#pragma once

#include "Player.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Render();
	void		Release();

private:
	CObj*		m_pPlayer;
	list<CObj*>	m_BulletList;
	HDC			m_DC;

	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};

// GetAsyncKeyState('W')

// 1. W, A, S, D 키에 따른 네 방향으로 총알 쏘기
// 2. 전체 화면보다 100 작은 사각형 그리고 총알이 그 사각형을 벗어날 경우 삭제
