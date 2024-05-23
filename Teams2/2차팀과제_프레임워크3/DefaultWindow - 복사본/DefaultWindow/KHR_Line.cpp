#include "stdafx.h"
#include "KHR_Line.h"
#include "ScrollMgr.h"

CKHR_Line::CKHR_Line()
{
}

CKHR_Line::CKHR_Line(LINEPOINT& tLeft, LINEPOINT& tRight)
	: m_tInfo(tLeft, tRight)
{
}

CKHR_Line::~CKHR_Line()
{
}

void CKHR_Line::Render(HDC hDC)
{
	int iScroll = SCROLL.Get_ScrollX();

	MoveToEx(hDC, (int)m_tInfo.tLeft.fX + iScroll, (int)m_tInfo.tLeft.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRight.fX + iScroll, (int)m_tInfo.tRight.fY);
}

float CKHR_Line::Get_Y(float _fPlayerPosX)
{
	float fGradient = (m_tInfo.tRight.fY - m_tInfo.tLeft.fY) / (m_tInfo.tRight.fX - m_tInfo.tLeft.fX);
	float fY = fGradient * (_fPlayerPosX - m_tInfo.tLeft.fX) + m_tInfo.tLeft.fY;

	return fY;
}

float CKHR_Line::Get_X(float _fPlayerPosY)
{
	float fGradient = (m_tInfo.tRight.fY - m_tInfo.tLeft.fY) / (m_tInfo.tRight.fX - m_tInfo.tLeft.fX);
	float fX = (_fPlayerPosY + (fGradient * m_tInfo.tLeft.fX) - m_tInfo.tLeft.fY) / fGradient;

	return fX;
}
