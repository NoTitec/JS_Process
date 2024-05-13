#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Grenade.h"
#include "CKeyMgr.h"

CPlayer::CPlayer()
	: m_pBulletList(nullptr)
	, m_ptCursorPos{}
{
    
}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    m_tInfo.fX = WINCX / 2.0f;
    m_tInfo.fY = WINCY / 2.0f;
    m_tInfo.fCX = 50.0f;
    m_tInfo.fCY = 50.0f;

    m_fSpeed = 3.0f;
}

int CPlayer::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
	// 마우스 커서 좌표를 기반으로 방향벡터를 구함.
	Dir_Update();
	// 방향을 기반으로 Posin 좌표를 구함.
	Posin_Update();
	
    Key_Update();

    CObj::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{

}

void CPlayer::Render(HDC _hdc)
{
    RECT PlayerRect = Get_Rect();
    Ellipse(_hdc, PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom);

	Cursor_Render(_hdc);
	Posin_Render(_hdc);
}

void CPlayer::Release()
{

}

void CPlayer::Key_Update()
{
	INFO PlayerInfo = Get_Info();

	if (KEY_HOLD(KEY::W))
	{
		PlayerInfo.fY -= m_fSpeed;
	}
	if (KEY_HOLD(KEY::S))
	{
		PlayerInfo.fY += m_fSpeed;
	}
	if (KEY_HOLD(KEY::A))
	{
		PlayerInfo.fX -= m_fSpeed;
	}
	if (KEY_HOLD(KEY::D))
	{
		PlayerInfo.fX += m_fSpeed;
	}

	// TAP : 키가 눌렸다.
	if (KEY_TAP(KEY::SPACE))
	{
		PlayerInfo.fCX = 0.f;
		PlayerInfo.fCY = 0.f;
	}
	// HOLD : 꾹 누르기.
	if (KEY_HOLD(KEY::SPACE))
	{
		
	}
	// AWAY : 키가 떼졌다.
	if (KEY_AWAY(KEY::SPACE))
	{
		PlayerInfo.fX += 100.f * m_vDir.fX;
		PlayerInfo.fY += 100.f * m_vDir.fY;

		PlayerInfo.fCX = 50.f;
		PlayerInfo.fCY = 50.f;
	}

	Set_Info(PlayerInfo);
}

void CPlayer::Posin_Update()
{
	Vec2 vDir = Get_Dir();
	Vec2 vPosin = Get_Pos();
	float fDistance = Get_Distance();
	
	vPosin.fX += vDir.fX * fDistance;
	vPosin.fY += vDir.fY * fDistance;

	Set_Posin(vPosin);
}

void CPlayer::Cursor_Render(HDC _hdc)
{
	//HBRUSH HollowBrush = (HBRUSH)GetStockObject(BS_HOLLOW);
	HBRUSH greenBrush = CreateSolidBrush(RGB(144, 215, 86));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, greenBrush);
	Ellipse(_hdc,
		m_ptCursorPos.x - 10.f, m_ptCursorPos.y - 10.f,
		m_ptCursorPos.x + 10.f, m_ptCursorPos.y + 10.f);
	POINT ptCursor = m_ptCursorPos;
	MoveToEx(_hdc, m_ptCursorPos.x - 9.f, m_ptCursorPos.y, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x - 3.f, m_ptCursorPos.y);
	MoveToEx(_hdc, m_ptCursorPos.x + 9.f, m_ptCursorPos.y, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x + 3.f, m_ptCursorPos.y);

	MoveToEx(_hdc, m_ptCursorPos.x, m_ptCursorPos.y - 9.f, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x, m_ptCursorPos.y - 3.f);
	MoveToEx(_hdc, m_ptCursorPos.x, m_ptCursorPos.y + 9.f, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x, m_ptCursorPos.y + 3.f);

	::SelectObject(_hdc, oldBrush);
	::DeleteObject(greenBrush);
	
}

void CPlayer::Dir_Update()
{
	// 마우스 좌표를 받아옴.
	GetCursorPos(&m_ptCursorPos);
	// 현재 창 기준 마우스 좌표를 받아옴.
	ScreenToClient(g_hWnd, &m_ptCursorPos);
	
	Vec2 vPos = Get_Pos();
	Vec2 vDir;

	vDir.fX = m_ptCursorPos.x - vPos.fX;
	vDir.fY = m_ptCursorPos.y - vPos.fY;
	// CursorPos - vPos 한 값을 Normalize.
	vDir.Normalize();

	Set_Dir(vDir);
}



