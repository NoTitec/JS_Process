#include "Box.h"

CBox::CBox()
{
}

CBox::~CBox()
{
    Release();
}

void CBox::Initialize()
{
    m_tInfo.fCX = 20.f;
    m_tInfo.fCY = 20.f;
}

int CBox::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CBox::Late_Update()
{
    if (0 >= m_tRect.left || WINCX <= m_tRect.right ||
        0 >= m_tRect.top || WINCY <= m_tRect.bottom)
    {
        Set_Dead();
    }
}

void CBox::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBox::Release()
{
}
