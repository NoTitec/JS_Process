#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_fSpeed(0.f), m_eDir(DIR_END) , m_bDead(false), m_fAngle(0.f), m_fDistance(0.f),m_pFrameKey(L"")
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}


CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left	= long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top		= long(m_tInfo.fY - m_tInfo.fCY / 2.f);
	m_tRect.right	= long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom	= long(m_tInfo.fY + m_tInfo.fCY / 2.f);
}

void CObj::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < g_dwTime)
	{
		++m_tFrame.iFrameStart;

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;

		m_tFrame.dwTime = g_dwTime;
	}
}

