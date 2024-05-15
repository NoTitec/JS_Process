#include "pch.h"
#include "CItem.h"

CItem::CItem()
{

}

CItem::~CItem()
{
    Release();
}

void CItem::Initialize()
{
    // CItem Initialize
    m_tInfo.fCX = 30.0f;
    m_tInfo.fCY = 30.0f;

    if (OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != m_iType)
    {
        m_dwSurviveTime = GetTickCount();
    }
}

int CItem::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }

    // CItem Update


    CObj::Update_Rect();
    return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
    if (m_dwSurviveTime + 5000 < GetTickCount() && OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL != m_iType)
    {
        m_bDead = true;
    }
}

void CItem::Render(HDC _hdc)
{
    // CItem Render

    switch ((OBJ_ITEM_TYPE)m_iType)
    {
    case OBJ_ITEM_TYPE::OBJ_ITEM_DRUG:
    {
        ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

        HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);

        ::Rectangle(_hdc, m_tRect.left + 10, m_tRect.top, m_tRect.right - 10, m_tRect.bottom);
        ::Rectangle(_hdc, m_tRect.left, m_tRect.top + 10, m_tRect.right, m_tRect.bottom - 10);

        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(redBrush);
        break;
    }
    case OBJ_ITEM_TYPE::OBJ_ITEM_BARRIER:
    {

        ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

        HBRUSH skyBlueBrush = CreateSolidBrush(RGB(135, 206, 235));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, skyBlueBrush);
        ::Ellipse(_hdc, m_tRect.left + 3, m_tRect.top + 3, m_tRect.right - 3, m_tRect.bottom - 3);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(skyBlueBrush);

        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
        oldBrush = (HBRUSH)::SelectObject(_hdc, blueBrush);
        ::Ellipse(_hdc, m_tRect.left + 8, m_tRect.top + 8, m_tRect.right - 8, m_tRect.bottom - 8);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(blueBrush);

        break;
    }
    case OBJ_ITEM_TYPE::OBJ_ITEM_PORTAL:
    {
        m_tInfo.fCX = 100.f;
        m_tInfo.fCY = 100.f;
        CObj::Update_Rect();
        
        HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);
        ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
        ::SelectObject(_hdc, oldBrush);
        ::DeleteObject(redBrush);

        break;
    }
    }
}

void CItem::Release()
{

}

