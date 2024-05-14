#include "pch.h"
#include "Bullet.h"
#include "Turret.h"

int CTurret::iSurviveTime = 10000;
int CTurret::iFireTime = 1000;

CTurret::CTurret() 
    : m_bBuild(false)
    , m_iHp(0)
    , dw_fireTime(GetTickCount())
    , dw_surviveTime(0)
    , dw_deadTime(0)
    , m_pBulletList{}
    , m_pZombieList{}
{

}

CTurret::~CTurret()
{
    Release();
}

void CTurret::Initialize()
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 0.f;
}

int CTurret::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
    
    if (m_bBuild)
    {
        for (auto& pZombie : *m_pZombieList)
        {
            float fZombieY = pZombie->Get_Info().fY;
            float fZombieX = pZombie->Get_Info().fX;

            float fTurretY = m_tInfo.fY;
            float fTurretX = m_tInfo.fX;

            float fDiffY = fZombieY - fTurretY;
            float fDiffX = fZombieX - fTurretX;

            float fR = std::sqrtf(((fZombieY - fTurretY) * (fZombieY - fTurretY)) + ((fZombieX - fTurretX) * (fZombieX - fTurretX)));

            m_vDir.fY = (fR == 0) ? 0 : (fDiffY / fR);
            m_vDir.fX = (fR == 0) ? 0 : (fDiffX / fR);
            m_vDir.Normalize();

            if (dw_fireTime + iFireTime < GetTickCount())
            {
                m_pBulletList->push_back(Create_Bullet());
                dw_fireTime = GetTickCount();
            }
        }
    }
    CObj::Update_Rect();
    return OBJ_NOEVENT;
}

void CTurret::Late_Update()
{
    if (Get_SurviveRatio() >= 1.0f)
    {
        m_bBuild = false;
        dw_surviveTime = 0;
        dw_deadTime = 0;
        dw_fireTime = 0;
    }
}

void CTurret::Render(HDC _hdc)
{
    if (m_bBuild)
    {
        HBRUSH brownBrush = CreateSolidBrush(RGB(101, 67, 33));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, brownBrush);
        ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(brownBrush);

        HPEN blackPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
        HPEN oldPen = (HPEN)::SelectObject(_hdc, blackPen);
        ::MoveToEx(_hdc, m_tInfo.fX, m_tInfo.fY, NULL);
        ::LineTo(_hdc, m_tInfo.fX + 35 * m_vDir.fX, m_tInfo.fY + 35 * m_vDir.fY);
        ::SelectObject(_hdc, oldPen);
        ::DeleteObject(blackPen);

        ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

        HBRUSH orangeBrush = CreateSolidBrush(RGB(255, 204, 0));
        oldBrush = (HBRUSH)::SelectObject(_hdc, orangeBrush);

        float fSurviveRatio = Get_SurviveRatio();

        float fScaledfCX = m_tInfo.fCX * fSurviveRatio;
        float fScaledfCY = m_tInfo.fCY * fSurviveRatio;
        ::Ellipse(
            _hdc,
            m_tInfo.fX - fScaledfCX / 2.0f,
            m_tInfo.fY - fScaledfCY / 2.0f,
            m_tInfo.fX + fScaledfCX / 2.0f,
            m_tInfo.fY + fScaledfCY / 2.0f
        );

        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(oldBrush);
    }
    else
    {
        HBRUSH brownBrush = CreateSolidBrush(RGB(101, 67, 33));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, brownBrush);
        ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(brownBrush);
    }
}

void CTurret::Release()
{

}

CObj* CTurret::Create_Bullet()
{
    CObj* pNewBullet = new CBullet;
    pNewBullet->Initialize();
    pNewBullet->Set_Pos(m_tInfo.fX + 35 * m_vDir.fX, m_tInfo.fY + 35 * m_vDir.fY);
    pNewBullet->Set_Dir(Vec2{ m_vDir.fX, m_vDir.fY });
    return pNewBullet;
}

float CTurret::Get_SurviveRatio()
{
    return (float)(GetTickCount() - dw_surviveTime) / (float)(dw_deadTime - dw_surviveTime);
}
