#pragma once

#include "Player.h"
#include "Monster.h"

class CMainGame
{
	DECLARE_SINGLE(CMainGame);

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

public:
	HWND		Get_HWND() { return m_HWND; }
	HDC			Get_HDC() { return  m_HDC; }

private:
	HWND		m_HWND;
	HDC			m_HDC;

private:
	HDC			m_DC;

private:
	HDC			m_BackDC;
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOldBitmap;

};

// vertex(정점) -> polygon(면) -> subset(파츠) -> mesh(모델링)
 
// 그리기 연산의 최소 단위 : vertex
// 그리기 최소 단위 : polygon
 
// 버텍스 프로세싱 = 정점의 변환 + 조명(명암) 연산



