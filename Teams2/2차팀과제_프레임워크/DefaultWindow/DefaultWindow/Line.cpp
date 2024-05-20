#include "stdafx.h"
#include "Line.h"


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
	MoveToEx(hDC, (int)m_tInfo.tLeft.fX, (int)m_tInfo.tLeft.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRight.fX, (int)m_tInfo.tRight.fY);
}
