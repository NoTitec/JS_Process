#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "Shield.h"
#include "ScrewBullet.h"

CPlayer::CPlayer() : m_pBullet(nullptr), m_pShield(nullptr)
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	m_tPosin.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle * (PI / 180.f)));
	m_tPosin.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	// 포신 그리기

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release()
{
}

template<typename T>
CObj * CPlayer::Create_Bullet()
{
	CObj*		pBullet = CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}

void CPlayer::Key_Input()
{
	// GetKeyState()

	/*if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	else if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;*/
		
	if (GetAsyncKeyState(VK_RIGHT))
		m_fAngle -= 5.f;
	
	if (GetAsyncKeyState(VK_LEFT))
		m_fAngle += 5.f;

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX += -m_fSpeed * cos(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= -m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Create_Bullet<CScrewBullet>());
	}

	if (GetAsyncKeyState('S'))
	{
		m_pShield->push_back(Create_Shield());
	}

}


CObj * CPlayer::Create_Shield()
{
	CObj*		pShield = CAbstractFactory<CShield>::Create();
	pShield->Set_Target(this);

	return pShield;
}

