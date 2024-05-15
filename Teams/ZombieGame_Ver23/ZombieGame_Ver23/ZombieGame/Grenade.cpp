#include "pch.h"
#include "Grenade.h"
#include "Bomb.h"

CGrenade::CGrenade() : m_bTimeOver(false)
{
}

CGrenade::~CGrenade()
{
	Release();
}

void CGrenade::Initialize()
{
	m_tInfo.fCX = 20.0f;
	m_tInfo.fCY = 20.0f;
	m_fSpeed = 8.0f;
}

int CGrenade::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	m_fSpeed -= 0.045f;
	m_fSpeed = m_fSpeed < 0.f ? 0.f : m_fSpeed;

	m_tInfo.fX += m_fSpeed * m_tInfo.fNormalX;
	m_tInfo.fY += m_fSpeed * m_tInfo.fNormalY;
	
	CObj::Update_Rect();
	return OBJ_NOEVENT;
}

void CGrenade::Late_Update()
{
	float fCurrentNormalY = m_tInfo.fNormalY;
	float fCurrentNormalX = m_tInfo.fNormalX;

	bool bTouchLeftWall = m_tRect.left <= 0;
	bool bTouchRightWall = m_tRect.right >= WINCX;
	bool bTouchTopWall = m_tRect.top <= 0;
	bool bTouchBottomWall = m_tRect.bottom >= WINCY;

	float theta = acosf(m_tInfo.fNormalX);
	float degree = (float)theta * (180 / PI);

	if (bTouchLeftWall || bTouchRightWall)
	{
		m_tInfo.fNormalX = -m_tInfo.fNormalX;
	}
	
	if (bTouchBottomWall || bTouchTopWall)
	{
		m_tInfo.fNormalY = -m_tInfo.fNormalY;
	}

	if (m_fSpeed == 0)
	{
		m_bTimeOver = true;
		m_pBombList->push_back(Create_Bomb());
		Set_Dead();
	}
}

void CGrenade::Render(HDC _hdc)
{
	HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 127));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, greenBrush);
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(greenBrush);
}

void CGrenade::Release()
{
	
}

CObj* CGrenade::Create_Bomb()
{
	CObj* pNewBomb = new CBomb;
	pNewBomb->Initialize();
	pNewBomb->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	return pNewBomb;
}
