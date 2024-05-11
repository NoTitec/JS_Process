#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Grenade.h"
#include "CKeyMgr.h"

CPlayer::CPlayer() 
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
    Rectangle(_hdc, PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom);
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

	// TAP : Å°°¡ ´­·È´Ù.
	if (KEY_TAP(KEY::SPACE))
	{

	}
	// HOLD : ²Ú ´©¸£±â.
	if (KEY_HOLD(KEY::SPACE))
	{

	}
	// AWAY : Å°°¡ ¶¼Á³´Ù.
	if (KEY_AWAY(KEY::SPACE))
	{

	}

	Set_Info(PlayerInfo);
}
void CPlayer::Update_Dir()
{
}



