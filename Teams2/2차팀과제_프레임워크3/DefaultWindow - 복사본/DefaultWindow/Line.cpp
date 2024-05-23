#include "stdafx.h"
#include "Line.h"
#include "ScrollMgr.h"

CLine::CLine()
{
}

CLine::CLine(LINEPOINT & tLeft, LINEPOINT & tRight)
	: m_tInfo(tLeft, tRight)
{
}


CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	float fScrollX = SCROLL.Get_ScrollX();
	MoveToEx(hDC, (int)m_tInfo.tLeft.fX + fScrollX, (int)m_tInfo.tLeft.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRight.fX + fScrollX, (int)m_tInfo.tRight.fY);

}
