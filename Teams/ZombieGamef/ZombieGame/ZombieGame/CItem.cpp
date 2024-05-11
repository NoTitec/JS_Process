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
    
    // m_tInfo.fCX = 50.0f;
    // m_tInfo.fCY = 50.0f;
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
    
}

void CItem::Render(HDC _hdc)
{
   // CItem Render
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /* HBRUSH itemBrush = nullptr;
    HBRUSH oldBrush = nullptr;
    SetBkMode(_hdc, TRANSPARENT);

    switch (m_eItemType)
    {
    case OBJ_ITEM_TYPE::GUN:
    {
        itemBrush = CreateSolidBrush(RGB(133, 94, 66));
        oldBrush = (HBRUSH)::SelectObject(_hdc, itemBrush);
        ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
        ::TextOut(_hdc, m_tInfo.fX, m_tInfo.fY, L"GUN", 3);
        break;
    }
    }
    SetBkMode(_hdc, OPAQUE);
    ::SelectObject(_hdc, oldBrush);
    ::DeleteObject(itemBrush);*/
}

void CItem::Release()
{
}

void CItem::Update_Dir()
{
}
