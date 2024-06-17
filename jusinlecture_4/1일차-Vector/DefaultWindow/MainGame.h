#pragma once

#include "Player.h"
#include "Monster.h"

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
	CObj*		m_pMonster;
	HDC			m_DC;

};

// vertex(����) -> polygon(��) -> subset(����) -> mesh(�𵨸�)
 
// �׸��� ������ �ּ� ���� : vertex
// �׸��� �ּ� ���� : polygon
 
// ���ؽ� ���μ��� = ������ ��ȯ + ����(���) ����



