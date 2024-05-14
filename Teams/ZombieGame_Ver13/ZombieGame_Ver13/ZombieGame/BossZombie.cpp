#include "pch.h"
#include "BossZombie.h"
#include <random>

CBossZombie::CBossZombie() :m_bStuck(false), m_iPatternType(0)
{

}

CBossZombie::~CBossZombie()
{
    Release();
}

void CBossZombie::Dir_Update()
{
}

void CBossZombie::Initialize()
{
    m_dwPatternTime = m_dwMoveTime = GetTickCount();
    Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
    //중 상단 생성
    m_tInfo.fX = WINCX / 2.0f;
    m_tInfo.fY = WINCY / 4.0f;
    m_tInfo.fCX = 80.0f;
    m_tInfo.fCY = 80.0f;
    m_fSpeed = 2.0f;
    m_iHP = 50;
    m_iFullHp = 50;
}

int CBossZombie::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
    //3초마다 패턴공격 순서대로 + 이동방향 변경
    if (m_dwPatternTime + 3000 < GetTickCount())
    {
        Pattern_Attack(m_iPatternType);
        if (++m_iPatternType == 4)
        {
            m_iPatternType = 0;
        }
        Random_Dir_Degree();
    }
    CObj::Update_Rect();
    Pos_Hp_Bar_Update();
    return OBJ_NOEVENT;
}

void CBossZombie::Late_Update()
{
}

void CBossZombie::Render(HDC _hdc)
{
    //가운데 원이랑 주변 상하좌우 사각형 하나씩
    ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left-40.f, m_tRect.top, m_tRect.right-40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top-40.f, m_tRect.right, m_tRect.bottom-40.f);
    ::Rectangle(_hdc, m_tRect.left+40.f, m_tRect.top, m_tRect.right+40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top+40.f, m_tRect.right, m_tRect.bottom+40.f);

}

void CBossZombie::Release()
{
}

void CBossZombie::Pattern_Attack(int _patterntype)
{
    switch (_patterntype)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void CBossZombie::Random_Dir_Degree()
{
    int randomDegree = rand() % 360;
    m_fDegree = randomDegree;
}

void CBossZombie::Pos_Hp_Bar_Update()
{
}
