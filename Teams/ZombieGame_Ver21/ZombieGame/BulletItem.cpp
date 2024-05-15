#include "pch.h"
#include "BulletItem.h"

CBulletItem::CBulletItem()
{
}

CBulletItem::~CBulletItem()
{
}

void CBulletItem::Initialize()
{
    m_tInfo.fCX = 30.0f;
    m_tInfo.fCY = 30.0f;
    m_dwSurviveTime = GetTickCount();
}

int CBulletItem::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }

    CObj::Update_Rect();
    return 0;
}

void CBulletItem::Late_Update()
{
    if (m_dwSurviveTime + 5000 < GetTickCount())
    {
        m_bDead = true;
    }
}

void CBulletItem::Render(HDC _hdc)
{
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

    switch ((BULLET_TYPE)m_iType)
    {
    case BULLET_TYPE::GRENADE_BULLET:
    {
        HBRUSH greenBrush = CreateSolidBrush(RGB(77, 120, 7));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, greenBrush);
        ::Ellipse(_hdc, m_tRect.left + 5, m_tRect.top + 5, m_tRect.right - 5, m_tRect.bottom - 5);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(greenBrush);

        break;
    }
    case BULLET_TYPE::NORMAL_BULLET:
    {
        HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, yellowBrush);
        ::Ellipse(_hdc, m_tRect.left + 5, m_tRect.top + 5, m_tRect.right - 5, m_tRect.bottom - 5);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(yellowBrush);

        break;
    }
    case BULLET_TYPE::SHOTGUN_BULLET:
    {
        HBRUSH yellowBrush = CreateSolidBrush(RGB(249, 166, 2));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, yellowBrush);
        ::Ellipse(_hdc, m_tRect.left + 5, m_tRect.top + 5, m_tRect.right - 5, m_tRect.bottom - 5);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(yellowBrush);
        break;
    }
    }
}

void CBulletItem::Release()
{
}
