#include "pch.h"
#include "Obj.h"

CObj::CObj()
	: m_fSpeed(0.f)
	, m_fDegree(0.f)
	, m_fDistance(30.f)
	, m_iType(0)
	, m_bDead(false)
	, m_bRandDir(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_vDir, sizeof(Vec2));
	ZeroMemory(&m_vPosin, sizeof(Vec2));
}

CObj::~CObj()
{
}

void CObj::Dir_Update()
{
}

void CObj::Posin_Update()
{
	// m_vDir를 기반으로 포신 좌표를 구함.
	m_vPosin.fX = m_tInfo.fX + (m_vDir * m_fDistance).fX;
	m_vPosin.fY = m_tInfo.fY + (m_vDir * m_fDistance).fY;
	
}

void CObj::Posin_Render(HDC hDC)
{
	//HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
	//HPEN oldPen = (HPEN)::SelectObject(hDC, blackPen);
	
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);

	LineTo(hDC, m_vPosin.fX, m_vPosin.fY);
	//::SelectObject(hDC, oldPen);
	//::DeleteObject(blackPen);
}

void CObj::Update_Rect()
{
	m_tRect.left = long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top = long(m_tInfo.fY - m_tInfo.fCY / 2.f);
	m_tRect.right = long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom = long(m_tInfo.fY + m_tInfo.fCY / 2.f);
}
