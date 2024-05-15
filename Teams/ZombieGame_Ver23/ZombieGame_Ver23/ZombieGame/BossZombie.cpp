#include "pch.h"
#include "BossZombie.h"
#include "BossHpBar.h"
#include "AbstractFactory.h"
#include "Bullet.h"
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
    Vec2 vDir;
    Vec2 vPos = Get_Pos();
    vDir = m_vTargetPos - vPos;
    vDir.Normalize();

    Set_Dir(vDir);
}

void CBossZombie::Initialize()
{
    m_dwMoveTime = GetTickCount();
    m_CollisionTime = GetTickCount();
    m_ePattern = BOSSPATTERN(rand() % END_PATTERN);
    Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
    //�� ��� ����
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
    // Player ��ǥ ���� ���⺤�� ������Ʈ
    Dir_Update();
    
    //���ϰ��� ���� �Լ� ȣ��
    Pattern();
    //3�ʸ��� �̵����� ����
    if (m_dwMoveTime + 3000 < GetTickCount())
    {
        Random_Dir_Degree();
        // ��ƽī��Ʈ ���� �ٸ��� �����ϰŰ��� 
        // ���� ���� ����������� ��������� �Լ� ȣ��Ƚ�� üũ�ϴ�
        // ������ ���� �Լ��� 100�� ȣ��ÿ� ������ ���´�.
        // �̷������ζ� �غ��� ���� 
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
    //��� ���̶� �ֺ� �����¿� �簢�� �ϳ���
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

    m_pBossHpBar->Render(_hdc);
}

void CBossZombie::Release()
{
    Safe_Delete<CBossHpBar*>(m_pBossHpBar);
}

CObj* CBossZombie::Create_Follow_Bullet()
{
    m_pBossBulletList->push_back(CAbstractFactory<CBullet>::Create());
    CObj* pBullet = m_pBossBulletList->back();
    pBullet->Set_Pos(Get_Pos()); // �������� ��ǥ
    Vec2 vPlayerDir = Get_Dir();
    pBullet->Set_Dir(vPlayerDir); // ���� ���� >>> �÷��̾� ��ġ (�븻������ �Ѱ�)
    pBullet->Set_Type((int)NORMAL_BULLET); // ���� Ÿ��.

    if (m_iType == (int)GRENADE_BULLET)
    {
        pBullet->Set_Speed(12.f);
    }
    return nullptr;
}
void CBossZombie::Pattern()
{
    ULONGLONG tmp = GetTickCount64();
    if (tmp - m_fSaveTime > m_fPatternCoolTime)
    {
        m_fSaveTime = tmp;
        switch (m_ePattern)
        {
        case FOLLOWBULLET:
            m_ePattern = Pattern1();
            break;
            //�ٸ� ���ϵ� �߰��� �� case ���� �߰�
        }
    }
}

BOSSPATTERN CBossZombie::Pattern1()
{
    //�������Ͱ� �ڱ� bullet����Ʈ�� ���Ϻ� �Ѿ� �÷��̾� Ÿ������ �����ؼ� push�ϸ�
    // �Ѿ� ������ �÷��̾� ��ġ������ ���ư����� initialize���� �����Ǿ����
    Create_Follow_Bullet();
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
