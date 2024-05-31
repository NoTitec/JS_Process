#include "GreenBoss.h"
#include "EventDefine.h"
#include "BmpMgr.h"
CGreenBoss::CGreenBoss()
{
}

CGreenBoss::~CGreenBoss()
{
    Release();

}

void CGreenBoss::Initialize()
{
    m_tInfo = { 600.f, WINCY / 2.f, 82.f, 72.f };
    //m_tInfo.fCX = 82.f;
    //m_tInfo.fCY = 72.f;

    m_fSpeed = 4.f;
    //���Ͻð�����
    m_fSaveTime = GetTickCount();
    m_fCoolTime = 4000.f;

    m_eCurState = IDLE;
    m_ePattern = BOSS_PATTERN_END;
    //��Ʈ�̹��� ����
    m_tFrame.iFrameStart = 0;
    //��Ʈ�̹��� �ִ� ����
    m_tFrame.iFrameEnd = 3;
    //��Ʈ�̹��� ����
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 200;
    m_pFrameKey = L"GreenBoss_Idle";
}

int CGreenBoss::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    //���ϻ��¶� �ٸ����ϰ��ݹ�����������
    //if ((m_fSaveTime + m_fCoolTime<GetTickCount()) && m_eCurState == IDLE)
    //{
    //    //�����¸� ���ϻ��·� ��ȯ�ϴ��Լ�
    //    Change_State();
    //    m_fSaveTime = GetTickCount();
    //}
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CGreenBoss::Late_Update()
{
    Motion_Change();
    __super::Move_Frame();
}

void CGreenBoss::Render(HDC hDC)
{
    int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

    GdiTransparentBlt(hDC,
        m_tRect.left + iScrollX,
        m_tRect.top + iScrollY,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        (int)m_tInfo.fCX * m_tFrame.iFrameStart,
        (int)m_tInfo.fCY * m_tFrame.iMotion,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(255, 0, 152));
}

void CGreenBoss::Release()
{
}

void CGreenBoss::Change_State()
{
    m_eCurState = ATTACK;

    int irandomnumber = rand() % 2;

    switch (irandomnumber)
    {
    case ONEPATTERN:
        Pattern1();
        break;
    case TWOPATTERN:
        Pattern2();
        break;
    }
}

void CGreenBoss::Pattern1()
{
    //���ҽ� �۾��ϰ� �߰�
    m_pFrameKey = L"GreenBoss_Idle";
    m_eCurState = IDLE;
}

void CGreenBoss::Pattern2()
{
    //���ҽ� �۾��ϰ� �߰�
    m_pFrameKey = L"GreenBoss_Idle";
    m_eCurState = IDLE;
}

void CGreenBoss::Motion_Change()
{
    if (m_ePreState != m_eCurState)
    {
        switch (m_eCurState)
        {
        case CGreenBoss::IDLE:
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 200;
            break;
        case CGreenBoss::ATTACK:
            switch (m_ePattern)
            {
            case CGreenBoss::ONEPATTERN:
                m_tFrame.iFrameStart = 0;
                m_tFrame.iFrameEnd = 2;
                m_tFrame.iMotion = 0;
                m_tFrame.dwTime = GetTickCount();
                m_tFrame.dwSpeed = 100;
                break;
            case CGreenBoss::TWOPATTERN:
                m_tFrame.iFrameStart = 0;
                m_tFrame.iFrameEnd = 2;
                m_tFrame.iMotion = 0;
                m_tFrame.dwTime = GetTickCount();
                m_tFrame.dwSpeed = 100;
                break;
            }
            break;
        }
        m_ePreState = m_eCurState;

    }
}
