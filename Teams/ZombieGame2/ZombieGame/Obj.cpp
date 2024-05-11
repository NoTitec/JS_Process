#include "pch.h"
#include "Obj.h"

CObj::CObj() : m_fSpeed(0), m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left	= long(m_tInfo.fX - m_tInfo.fCX / 2.0f);
	m_tRect.top		= long(m_tInfo.fY - m_tInfo.fCY / 2.0f);
	m_tRect.right	= long(m_tInfo.fX + m_tInfo.fCX / 2.0f);
	m_tRect.bottom	= long(m_tInfo.fY + m_tInfo.fCY / 2.0f);
}
