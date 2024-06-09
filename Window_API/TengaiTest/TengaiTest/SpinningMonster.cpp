#include "SpinningMonster.h"
#include "GreenBossDeadEffect.h"
#include "SG1MonsterSpawnMgr.h"
CSpinningMonster::CSpinningMonster()
{
}

CSpinningMonster::~CSpinningMonster()
{
	Release();
}

void CSpinningMonster::Initialize()
{
    m_eID = OBJ_MONSTER;
    m_tInfo.fX = 700.f;
    m_tInfo.fY = 100.f;
    m_tInfo.fCX = 42.f;
    m_tInfo.fCY = 48.f;
    m_iHp = 20;
    m_fSpeed = 1.f;
    //���Ͻð�����
    m_fSaveTime = GetTickCount();
    m_fCoolTime = 2000.f;

    m_eCurState = IDLE;
    //��Ʈ�̹��� ����
    m_tFrame.iFrameStart = -1;
    //��Ʈ�̹��� �ִ� ����
    m_tFrame.iFrameEnd = 3;
    //��Ʈ�̹��� ����
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 200;
    m_pFrameKey = L"SpinningMonster";
    m_tFrame.bRepeat = true;
    m_bSpawnInit = true;
    m_AttackEnd = false;
}

int CSpinningMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    //���� ���Ͽ����� ������Ʈ
    switch (m_eCurState)
    {
    case IDLE:
        if (m_bSpawnInit)
        {
            m_tInfo.fX -= 2.f;
            if(m_tInfo.fX<650.f)
                m_bSpawnInit = false;
        }
            
        else
        {
            //���ϻ��¶� �ٸ����ϰ��ݹ�����������
            if ((m_fSaveTime + m_fCoolTime < GetTickCount()))
            {
                //�����¸� ���ϻ��·� ��ȯ�ϴ��Լ�
                Change_State();
                m_fSaveTime = GetTickCount();
                m_fAngle = rand() % 360;
            }
            m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
            m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;
        }
        break;
    case ATTACK:
        if (m_AttackEnd)
        {
            Set_State_Idle();
            m_AttackEnd = false;
        }
           
        break;

    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CSpinningMonster::Late_Update()
{
    Motion_Change();
    if ((m_HitFrameSaveTime + 200 < GetTickCount()))
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"SpinningMonster";
            m_tFrame.bRepeat = true;
            break;
        case ATTACK:
            m_pFrameKey = L"Spinning_Attack";
            m_tFrame.bRepeat = false;
        }

    }
    __super::Move_Frame();
    
    int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
    //���浹�̸� angle 180~360
    //���浹�̸� 0~180
    //���浹�̸� 0~90or 270~360
    //���浹�̸� 90~270
    // ���浹
    if (m_tInfo.fX < 18) {
        int rand1 = rand() % 90;
        int rand2 = 270 + (rand() % 90);
        if (rand() % 2 == 0)
        {
            m_fAngle = rand1;
        }
        else
        {
            m_fAngle = rand2;
        }
        if (m_fAngle < 0) m_fAngle += 360;  // ����ȭ
    }
    // ���浹
    if (m_tInfo.fX > 782) {
        m_fAngle = 90 + (rand() % 180);
        if (m_fAngle >= 360) m_fAngle -= 360;  // ����ȭ
    }
    // ���浹
    if (m_tInfo.fY + iScrollY < 18) {
        m_fAngle = 180 + (rand() % 180);
        if (m_fAngle < 0) m_fAngle += 360;  // ����ȭ
    }
    // ���浹
    if (m_tInfo.fY + iScrollY > 582) {
        m_fAngle = rand() % 180;
        if (m_fAngle >= 360) m_fAngle -= 360;  // ����ȭ
    }
}

void CSpinningMonster::Render(HDC hDC)
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
        RGB(255, 0, 212));
}

void CSpinningMonster::Release()
{
    ObjMgr->Add_Object(OBJ_EFFECT, CAbstractFactory<CGreenBossDeadEffect>::Create(m_tInfo.fX, m_tInfo.fY));
    SG1MonsterSpawnMgr->KillCountUp();
}

void CSpinningMonster::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYERBOMB:
        //cout << "bombattacked" << endl;
    case OBJ_PLAYERBULLET:
        m_HitFrameSaveTime = GetTickCount();
        --m_iHp;
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"SpinningMonster_White";
            m_tFrame.bRepeat = false;
            break;
        case ATTACK:
            m_pFrameKey = L"Spinning_Attack_White";
            m_tFrame.bRepeat = false;
            break;
        }
        if (m_iHp == 0)
            Set_Dead();
        break;
    case OBJ_PETBULLET:
        m_HitFrameSaveTime = GetTickCount();
        --m_iHp;
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"SpinningMonster_White";
            m_tFrame.bRepeat = false;
            break;
        case ATTACK:
            m_pFrameKey = L"Spinning_Attack_White";
            m_tFrame.bRepeat = false;
            break;
        }
        if (m_iHp == 0)
            Set_Dead();
        break;
    }
}

void CSpinningMonster::On_Motion_End()
{
    if (m_tFrame.bRepeat != true)
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"SpinningMonster";
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 200;
            //m_tFrame.bRepeat = true;
            //m_AttackEnd = true;
            break;
        case ATTACK:
            m_pFrameKey = L"SpinningMonster";
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 200;
            //m_tFrame.bRepeat = false;
  
            m_AttackEnd = true;
            break;
        }
    }
}

void CSpinningMonster::Change_State()
{
    m_eCurState = ATTACK;
    Pattern1();
}

void CSpinningMonster::Pattern1()
{
    m_pFrameKey = L"Spinning_Attack";
    //�ش� ��������Ʈ �ݺ��ƴ� ����ؾ���!!!!!!!!!!!!
    m_tFrame.bRepeat = false;
    //���� �Ѿ� �����ڵ�(�Ѿ� Ŭ���� �����ʿ�)
    cout << "�ܼ� �Ѿ� ���� Ȯ�ο�" << endl;
}

void CSpinningMonster::Motion_Change()
{
    if (m_ePreState != m_eCurState)
    {
        switch (m_eCurState)
        {
        case CSpinningMonster::IDLE:
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 200;
            break;
        case CSpinningMonster::ATTACK:

            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 100;
            break;

        }
    }
    m_ePreState = m_eCurState;

    
}

void CSpinningMonster::Move_Frame_once_and_Return_Idle_State()
{
    if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
    {
        ++m_tFrame.iFrameStart;

        if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
            Set_State_Idle();

        m_tFrame.dwTime = GetTickCount();
    }
}
