#pragma once
#include "Singleton.h"
#include "Define.h"

class CScrollMgr :public CSingleton<CScrollMgr>
{
	friend CSingleton<CScrollMgr>;
private:
	CScrollMgr();
	~CScrollMgr();

public:
	float		Get_ScrollX() { return m_fScrollX; }
	float		Get_ScrollY() { return m_fScrollY; }

public:
	void		Set_ScrollX(float _fX) { m_fScrollX += _fX; }
	void		Set_ScrollY(float _fY) { m_fScrollY += _fY; }

	void		Scroll_Lock(int _fMapCX,int _fMapCY);
private:
	static CScrollMgr*	m_pInstance;

	float		m_fScrollX;
	float		m_fScrollY;
};

#define SCROLL CScrollMgr::Get_Instance()

