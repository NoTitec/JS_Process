#include "Line.h"

CLine::CLine()
{
}

CLine::CLine(LINEPOINT& tLeft, LINEPOINT& tRight)
	: m_LineInfo(tLeft, tRight)
{
}


CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_LineInfo.LeftPoint.fX, (int)m_LineInfo.LeftPoint.fY, nullptr);
	LineTo(hDC, (int)m_LineInfo.RightPoint.fX, (int)m_LineInfo.RightPoint.fY);
}