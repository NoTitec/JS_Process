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

// vertex(정점) -> polygon(면) -> subset(파츠) -> mesh(모델링)
 
// 그리기 연산의 최소 단위 : vertex
// 그리기 최소 단위 : polygon
 
// 버텍스 프로세싱 = 정점의 변환 + 조명(명암) 연산



