#include "stdafx.h"
#include "ScrollMgr.h"

CScrollMgr::CScrollMgr() : m_fScrollX(0.f), m_fScrollY(0.f)
{
}


CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Scroll_Lock(int _fMapCX, int _fMapCY)
{
	if (0.f < m_fScrollX)
		m_fScrollX = 0.f;

	if (0.f < m_fScrollY)
		m_fScrollY = 0.f;

	if (WINCX - _fMapCX > m_fScrollX)
		m_fScrollX = WINCX - _fMapCX;

	if (WINCY - _fMapCY > m_fScrollY)
		m_fScrollY = WINCY - _fMapCY;
}

