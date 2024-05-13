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
    Set_Scale(Vec2(10.f, 10.f));
}

int CBarrier::Update()
{

    BarrierType1();


    Update_Rect();

    return 0;
}

void CBarrier::Late_Update()
{
}

void CBarrier::Render(HDC _hdc)
{
    ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBarrier::Release()
{
}

void CBarrier::PlayerPos_Update(Vec2 _vPlayerPos)
{
    m_vPlayerPos = _vPlayerPos;
}

void CBarrier::BarrierType1()
{
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
