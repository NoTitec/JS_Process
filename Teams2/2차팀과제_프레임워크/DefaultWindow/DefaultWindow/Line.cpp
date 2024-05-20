#include "stdafx.h"
#include "Line.h"
#include "RenderMgr.h"

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
	RENDER.DrawLine(m_tInfo);
	/*MoveToEx(hDC, (int)m_tInfo.tLeft.fX, (int)m_tInfo.tLeft.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRight.fX, (int)m_tInfo.tRight.fY);*/
}
