#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };

	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	//Key_Input();

	//아래 벡터이동대신 마우스위치로 추적하는 코드 삽입
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	//
	m_tInfo.vDir.x = (float)pt.x-m_tInfo.vPos.x;
	m_tInfo.vDir.y = (float)pt.y-m_tInfo.vPos.y;
	//m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	float	fLength = sqrt(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;
	m_tInfo.vPos += m_tInfo.vDir*m_fSpeed;


	return 0;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		int(m_tInfo.vPos.x - 50.f), 
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// GetKeyState()

	
}
