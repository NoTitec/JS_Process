#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    m_tInfo = { WINCX / 2.f, WINCY / 4.f, 70.f, 70.f };
    m_fSpeed = 3.f;
    m_eDir = DIR_RIGHT;
}

int CMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    /*switch (m_eDir)
    {
    case DIR_LEFT:
        m_tInfo.fX -= m_fSpeed;
        break;
    case DIR_RIGHT:
        m_tInfo.fX += m_fSpeed;
        break;
    }*/
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
    /*if (100 >= m_tRect.left)
    {
        m_eDir = DIR_RIGHT;
    }
    if (WINCX - 100 <= m_tRect.right)
    {
        m_eDir = DIR_LEFT;
    }*/
    //ÃÑ¾ËÀÌ¶û Ãæµ¹½Ã deadº¯¼ö true·Î

}

void CMonster::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

RECT* CMonster::Get_Rect_Pointer()
{
    return &m_tRect;;
}
