#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Grenade.h"

CPlayer::CPlayer() : m_bGetShotgun(false), m_bGunmode(true)
{
    ZeroMemory(&m_mousePos, sizeof(POINT));
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

    Set_Theta_And_Degree();
    m_tInfo.fNormalX = std::cos(m_tInfo.fRad);
    m_tInfo.fNormalY = std::sin(m_tInfo.fRad);

    Key_Press();

    CObj::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{

}

void CPlayer::Render(HDC _hdc)
{
    float gunX = 35 * std::cos(m_tInfo.fRad);
    float gunY = 35 * std::sin(m_tInfo.fRad);
    ::MoveToEx(_hdc, m_tInfo.fX, m_tInfo.fY, NULL);

    HPEN grayPen = ::CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
    HPEN oldPen = (HPEN)::SelectObject(_hdc, grayPen);
    ::LineTo(_hdc, m_tInfo.fX + gunX, m_tInfo.fY + gunY);
    (HPEN)::SelectObject(_hdc, oldPen);
    ::DeleteObject(grayPen);

    HBRUSH greenBrush = ::CreateSolidBrush(RGB(60, 179, 113));
    HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, greenBrush);
    ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    (HBRUSH)::SelectObject(_hdc, oldBrush);
    ::DeleteObject(greenBrush);
}

void CPlayer::Release()
{

}

void CPlayer::Set_Theta_And_Degree()
{
    ::GetCursorPos(&m_mousePos);
    ::ScreenToClient(g_hWnd, &m_mousePos);

    float fDiffY = (float)(m_mousePos.y - m_tInfo.fY);
    float fDiffX = (float)(m_mousePos.x - m_tInfo.fX);
    float fR = (float)std::sqrt(fDiffY * fDiffY + fDiffX * fDiffX);
    
    m_tInfo.fRad = (float)std::atan2f(fDiffY, fDiffX);
    m_tInfo.fDegree = (m_tInfo.fRad * (180 / 3.14)) + (m_tInfo.fRad > 0 ? 0 : 360);
}

void CPlayer::Key_Press()
{
    float fDiffX = m_tInfo.fNormalX * m_fSpeed;
    float fDiffY = m_tInfo.fNormalY * m_fSpeed;
    
    if (GetAsyncKeyState('W'))
    {
        m_tInfo.fX += fDiffX;
        m_tInfo.fY += fDiffY;
    }

    if (GetAsyncKeyState('S'))
    {
        m_tInfo.fX -= fDiffX;
        m_tInfo.fY -= fDiffY;
    }

    if (GetAsyncKeyState('Q') & 0x0001)
    {
        m_bGunmode = m_bGunmode == true ? false : true;
    }

    if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
    {
        if (m_bGunmode)
        {
            if (m_bGetShotgun)
            {
                m_pBulletList->push_back(Create_Bullet(PI / 6.0f));
                m_pBulletList->push_back(Create_Bullet(0.f));
                m_pBulletList->push_back(Create_Bullet(-PI / 6.0f));
            }
            else
            {
                m_pBulletList->push_back(Create_Bullet(0.f));
            }
        }
        else
        {
            if (m_iTheNumberOfGrenades != 0)
            {
                m_pGrenadeList->push_back(Create_Grenade());
                --m_iTheNumberOfGrenades;
            }
        }
    }
}

CObj* CPlayer::Create_Grenade()
{
    CObj* pNewGrenade = new CGrenade;
    pNewGrenade->Initialize();

    float gunX = 35 * std::cos(m_tInfo.fRad);
    float gunY = 35 * std::sin(m_tInfo.fRad);

    pNewGrenade->Set_Pos(m_tInfo.fX + gunX, m_tInfo.fY + gunY);
    pNewGrenade->Set_Normal(m_tInfo.fNormalX, m_tInfo.fNormalY);
    dynamic_cast<CGrenade*>(pNewGrenade)->Set_BombList(m_pBombList);

    return pNewGrenade;
}

CObj* CPlayer::Create_Bullet(float _fInterval)
{
    CObj* pNewBullet = new CBullet;
    pNewBullet->Initialize();
    float gunX = 35 * std::cos(m_tInfo.fRad);
    float gunY = 35 * std::sin(m_tInfo.fRad);
    pNewBullet->Set_Pos(m_tInfo.fX + gunX, m_tInfo.fY + gunY);
    if (_fInterval == 0.f)
    {
        pNewBullet->Set_Normal(m_tInfo.fNormalX, m_tInfo.fNormalY);
    }
    else
    {
        float fNewRad = m_tInfo.fRad + _fInterval;
        
        float fNewNormalX = std::cos(fNewRad);
        float fNewNormalY = std::sin(fNewRad);

        pNewBullet->Set_Normal(fNewNormalX, fNewNormalY);
    }
    return pNewBullet;
}


