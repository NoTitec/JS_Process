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

// vertex(����) -> polygon(��) -> subset(����) -> mesh(�𵨸�)
 
// �׸��� ������ �ּ� ���� : vertex
// �׸��� �ּ� ���� : polygon
 
// ���ؽ� ���μ��� = ������ ��ȯ + ����(���) ����



