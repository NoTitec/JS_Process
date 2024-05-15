#include "pch.h"
#include "BossZombie.h"
#include "BossHpBar.h"

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
    m_dwPatternTime = GetTickCount();
    Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
    //중 상단 생성
    m_tInfo.fX = WINCX / 2.0f;
    m_tInfo.fY = WINCY / 4.0f;
    m_tInfo.fCX = 80.0f;
    m_tInfo.fCY = 80.0f;
    m_fSpeed = 1.0f;
    m_iHP = 50;
    m_iFullHp = 50;
    Random_Dir_Degree();
    m_pBossHpBar = new CBossHpBar();
    m_pBossHpBar->Set_Target(this);
    m_pBossHpBar->Initialize();
}

int CBossZombie::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
    //1초마다 패턴공격 순서대로 + 이동방향 변경
    if (m_dwPatternTime + 1000 < GetTickCount())
    {
        Pattern_Attack(m_iPatternType);
        if (++m_iPatternType == 4)
        {
            m_iPatternType = 0;
        }
        Random_Dir_Degree();
        m_dwPatternTime = GetTickCount();
    }
    
    m_tInfo.fX += m_fSpeed * cos(m_fDegree / 180.f * PI);
    m_tInfo.fY -= m_fSpeed * sin(m_fDegree / 180.f * PI);
    CObj::Update_Rect();
    

    m_pBossHpBar->Update();

    Pos_Hp_Bar_Update();
    return OBJ_NOEVENT;
}

void CBossZombie::Late_Update()
{
    m_pBossHpBar->Late_Update();
}

void CBossZombie::Render(HDC _hdc)
{
    //가운데 원이랑 주변 상하좌우 사각형 하나씩
    ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left - 40.f, m_tRect.top, m_tRect.right - 40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top - 40.f, m_tRect.right, m_tRect.bottom - 40.f);
    ::Rectangle(_hdc, m_tRect.left + 40.f, m_tRect.top, m_tRect.right + 40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top + 40.f, m_tRect.right, m_tRect.bottom + 40.f);

    m_pBossHpBar->Render(_hdc);
}

void CBossZombie::Release()
{
    Safe_Delete<CBossHpBar*>(m_pBossHpBar);
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
