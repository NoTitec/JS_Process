#include "pch.h"
#include "Barrier.h"

CBarrier::CBarrier()
    : m_vPlayerPos{}
{
}

CBarrier::~CBarrier()
{
}

void CBarrier::Initialize()
{
    Set_Degree(0.f);
    Set_Distance(50.f);
    Set_Scale(Vec2(20.f, 20.f));
}

int CBarrier::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }

    BarrierType1();


    Update_Rect();

    return 0;
}

void CBarrier::Late_Update()
{
}

void CBarrier::Render(HDC _hdc)
{
    //::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    HBRUSH skyBlueBrush = CreateSolidBrush(RGB(138, 247, 255));
    HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, skyBlueBrush);
    ::Ellipse(_hdc, m_tRect.left + 3, m_tRect.top + 3, m_tRect.right - 3, m_tRect.bottom - 3);
    ::SelectObject(_hdc, oldBrush);
    ::DeleteObject(skyBlueBrush);

    HBRUSH skywhiteBrush = CreateSolidBrush(RGB(229, 253, 255));
    oldBrush = (HBRUSH)::SelectObject(_hdc, skywhiteBrush);
    ::Ellipse(_hdc, m_tRect.left + 5, m_tRect.top + 5, m_tRect.right - 5, m_tRect.bottom - 5);
    ::SelectObject(_hdc, oldBrush);
    ::DeleteObject(skywhiteBrush);
}

void CBarrier::Release()
{
}

void CBarrier::PlayerPos_Update(Vec2 _vPlayerPos)
{
    m_vPlayerPos = _vPlayerPos;
}
UINT g_iBarrierCallCount;
void CBarrier::BarrierType1()
{
    ++g_iBarrierCallCount;
    if (g_iBarrierCallCount > 300)
    {
        g_iBarrierCallCount = 0;
        Set_Dead();
    }
    Vec2 vPos = Get_Pos();
    Vec2 vScale = Get_Scale();
    float Distance = Get_Distance();
    float vDegree = Get_Degree();
    vDegree += 15.f;
    vPos.fX = m_vPlayerPos.fX + Distance * cosf(vDegree * PI / 180);
    vPos.fY = m_vPlayerPos.fY + Distance * sinf(vDegree * PI / 180);


    Set_Pos(vPos);
    Set_Scale(vScale);
    Set_Degree(vDegree);
}
