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

// 1. W, A, S, D Ű�� ���� �� �������� �Ѿ� ���
// 2. ��ü ȭ�麸�� 100 ���� �簢�� �׸��� �Ѿ��� �� �簢���� ��� ��� ����
