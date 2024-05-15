#include "pch.h"
#include "BossZombie.h"
#include "BossHpBar.h"
#include <random>

CBossZombie::CBossZombie() :m_bStuck(false), m_fSaveTime(0), m_fPatternCoolTime(3000), m_ePattern(FOLLOWBULLET)
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
    m_dwMoveTime = GetTickCount();
    m_CollisionTime = GetTickCount();
    m_ePattern = BOSSPATTERN(rand() % END_PATTERN);
    Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
    //중 상단 생성
    m_tInfo.fX = WINCX / 2.0f;
    m_tInfo.fY = WINCY / 4.0f;
    m_tInfo.fCX = 80.0f;
    m_tInfo.fCY = 80.0f;
    m_fSpeed = 2.0f;
    m_iHP = 50;
    m_iFullHp = 50;

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
    // Player 좌표 기준 방향벡터 업데이트
    Dir_Update();

    m_vTargetPos;

    //패턴공격 관리 함수 호출
    Pattern();
    //3초마다 이동방향 변경
    if (m_dwMoveTime + 3000 < GetTickCount())
    {
        Random_Dir_Degree();
        m_dwMoveTime = GetTickCount();
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
    if (0.f >= m_tRect.left || WINCX <= m_tRect.right ||
        0.f >= m_tRect.top || WINCY <= m_tRect.bottom)
    {
        m_fDegree = m_fDegree + 180.0f;
    }
    m_pBossHpBar->Late_Update();
}

void CBossZombie::Render(HDC _hdc)
{
    //가운데 원이랑 주변 상하좌우 사각형 하나씩
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    ::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    POINT points[3];
    points[0].x = m_tRect.left;
    points[0].y = m_tRect.bottom;
    points[1].x = m_tInfo.fX;
    points[1].y = m_tRect.top;
    points[2].x = m_tRect.right;
    points[2].y = m_tRect.bottom;
    Polygon(_hdc, points, 3);
    /*::Rectangle(_hdc, m_tRect.left - 40.f, m_tRect.top, m_tRect.right - 40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top - 40.f, m_tRect.right, m_tRect.bottom - 40.f);
    ::Rectangle(_hdc, m_tRect.left + 40.f, m_tRect.top, m_tRect.right + 40.f, m_tRect.bottom);
    ::Rectangle(_hdc, m_tRect.left, m_tRect.top + 40.f, m_tRect.right, m_tRect.bottom + 40.f);*/

    m_pBossHpBar->Render(_hdc);
}

void CBossZombie::Release()
{
    Safe_Delete<CBossHpBar*>(m_pBossHpBar);
}


void CBossZombie::Pattern()
{
    ULONGLONG tmp = GetTickCount();
    if (tmp - m_fSaveTime > m_fPatternCoolTime)
    {
        m_fSaveTime = tmp;
        switch (m_ePattern)
        {
        case FOURDIRECTIONS:
            m_ePattern = Pattern1();
            break;
            //다른 패턴들 추가시 이 case 문에 추가
        }
    }
}

BOSSPATTERN CBossZombie::Pattern1()
{
    //보스몬스터가 자기 bullet리스트에 패턴별 총알 플레이어 타겟으로 생성해서 push하면
    // 총알 생성시 플레이어 위치쪽으로 날아가도록 initialize에서 지정되어야함

    return (BOSSPATTERN)(rand() % END_PATTERN);
}

void CBossZombie::Random_Dir_Degree()
{
    int randomDegree = rand() % 360;
    m_fDegree = randomDegree;
}

void CBossZombie::Pos_Hp_Bar_Update()
{

}
