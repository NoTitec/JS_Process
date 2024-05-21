#include "stdafx.h"
#include "RenderMgr.h"
#include "CKSHPlayer.h"
#include "KeyMgr.h"

CKSHPlayer::CKSHPlayer() : m_bJump(false), m_fTime(0.f), m_fPower(0.f)
{
    ZeroMemory(&m_tBarrel, sizeof(POINT));

}

CKSHPlayer::~CKSHPlayer()
{
    Release();
}

void CKSHPlayer::Initialize()
{
    m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
    m_fSpeed = 10.f;
    m_fDistance = 100.f;
    m_fPower = 20.f;
}

int CKSHPlayer::Update()
{
    Key_Input();
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CKSHPlayer::Late_Update()
{
    m_tBarrel.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle / 180.f * PI));
    m_tBarrel.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
}

void CKSHPlayer::Render(HDC hDC)
{
    RENDER.DrawRect(m_tRect);
    // 포신 그리기
    RENDER.DrawLine(Get_Info(), m_tBarrel);
    //MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
    //LineTo(hDC, m_tBarrel.x, m_tBarrel.y);
}

void CKSHPlayer::Release()
{
}

void CKSHPlayer::Key_Input()
{
    if (GetAsyncKeyState(VK_RIGHT))
        m_tInfo.fX += m_fSpeed;
    if (GetAsyncKeyState(VK_LEFT))
        m_tInfo.fX -= m_fSpeed;
    if (KEY.Key_Pressing('A'))
    {
        m_fAngle += 5.f;
    }
    if (KEY.Key_Pressing('D'))
    {
        m_fAngle -= 5.f;
    }
}
