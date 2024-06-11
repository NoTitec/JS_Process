#include "Hemisphere.h"
#include "EventDefine.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "AbstractFactory.h"
#include "PowerItem.h"
#include "BombItem.h"
#include "MonsterSpawnMgr.h"
#include "BladeMonster.h"
#include "GreenBoss.h"
#include "GreenBossDeadEffect.h"
#include "MonsterBullet1.h"
#include "SG1MonsterSpawnMgr.h"
CHemisphere::CHemisphere()
{
}

CHemisphere::~CHemisphere()
{
	Release();
}

void CHemisphere::Initialize()
{
    m_eID = OBJ_BOSSMONSTER;
    m_tInfo = { 600.f, WINCY / 2.f, 76.f,128.f };
    m_iHp = 40;
    m_fSpeed = 1.f;
    //���Ͻð�����
    m_fSaveTime = GetTickCount();
    m_fCoolTime = 5000.f;

    m_eCurState = IDLE;
    m_ePattern = BOSS_PATTERN_END;
    //��Ʈ�̹��� ����
    m_tFrame.iFrameStart = -1;
    //��Ʈ�̹��� �ִ� ����
    m_tFrame.iFrameEnd = 3;
    //��Ʈ�̹��� ����
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 100;
    m_pFrameKey = L"Boss2_Idle";
    m_tFrame.bRepeat = true;
    m_AttackEnd = false;
}

int CHemisphere::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    //���� ���Ͽ����� ������Ʈ
    switch (m_eCurState)
    {
    case IDLE:
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

        break;
    case ATTACK:
        if (m_AttackEnd)
        {
            Set_State_Idle();
            m_AttackEnd = false;
        }
        //switch (m_ePattern)
        //{
        //case ONEPATTERN:
        //    if (m_bMoveForward)
        //    {
        //        m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
        //        m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

        //        //printf("(%f, %f) \n", m_tInfo.fX, m_tInfo.fY);
        //        //printf("<%d, %d> \n", m_Pattern1EndPoint.x, m_Pattern1EndPoint.y);
        //        //���е� ������ ���������� ����ȯ�ؾ� ���� �Ȼ���
        //        if (abs(m_Pattern1EndPoint.x - (int)m_tInfo.fX) < 20 && abs(m_Pattern1EndPoint.y - (int)m_tInfo.fY) < 20)
        //            //if ((int)m_tInfo.fX == m_Pattern1EndPoint.x && (int)m_tInfo.fY == m_Pattern1EndPoint.y)
        //        {
        //            m_bMoveForward = false;
        //        }
        //    }
        //    else
        //    {
        //        m_tInfo.fX += cos(m_fAngle * PI / 180.f) * -m_fSpeed;
        //        m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * -m_fSpeed;
        //        if (abs(m_Pattern1StartPoint.x - (int)m_tInfo.fX) < 20 && abs(m_Pattern1StartPoint.y - (int)m_tInfo.fY) < 20)
        //            //if ((int)m_tInfo.fX == m_Pattern1StartPoint.x && (int)m_tInfo.fY == m_Pattern1StartPoint.y)
        //        {
        //            //m_bMoveForward = true;
        //            SoundMgr->StopSound(SOUND_BOSS_PATTERN1SOUND);
        //            Set_State_Idle();
        //        }
        //    }
        //    break;
        //case TWOPATTERN:
        //    break;
        //}
        break;
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CHemisphere::Late_Update()
{
    Motion_Change();
    if ((m_HitFrameSaveTime + 200 < GetTickCount()))
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"Boss2_Idle";
            m_tFrame.bRepeat = true;
            break;
        case ATTACK:
            m_pFrameKey = L"Boss2_Attack";
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

void CHemisphere::Render(HDC hDC)
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

void CHemisphere::Release()
{
    ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create(m_tInfo.fX, m_tInfo.fY));
    ObjMgr->Add_Object(OBJ_BOMB_ITEM, CAbstractFactory<CBombItem>::Create(m_tInfo.fX, m_tInfo.fY));
    ObjMgr->Add_Object(OBJ_EFFECT, CAbstractFactory<CGreenBossDeadEffect>::Create(m_tInfo.fX, m_tInfo.fY));
    SG1MonsterSpawnMgr->Set_BossMonsterDead();
}

void CHemisphere::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYERBOMB:
        //cout << "bombattacked" << endl;
    case OBJ_PLAYERBULLET:
        m_HitFrameSaveTime = GetTickCount();
        //--m_iHp;
        switch (m_eCurState)
        {
        /*case IDLE:
            m_pFrameKey = L"SpinningMonster_White";
            m_tFrame.bRepeat = false;
            break;*/
        case ATTACK:
            --m_iHp;
            m_pFrameKey = L"Boss2_Attack_White";
            m_tFrame.bRepeat = false;
            break;
        }
        if (m_iHp == 0)
            Set_Dead();
        break;
    case OBJ_PETBULLET:
        m_HitFrameSaveTime = GetTickCount();
        //--m_iHp;
        switch (m_eCurState)
        {
        /*case IDLE:
            m_pFrameKey = L"SpinningMonster_White";
            m_tFrame.bRepeat = false;
            break;*/
        case ATTACK:
            --m_iHp;
            m_pFrameKey = L"Boss2_Attack_White";
            m_tFrame.bRepeat = false;
            break;
        }
        if (m_iHp == 0)
            Set_Dead();
        break;
    }
}

void CHemisphere::On_Motion_End()
{
    if (m_tFrame.bRepeat != true)
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"Boss2_Idle";
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 100;
            //m_tFrame.bRepeat = true;
            //m_AttackEnd = true;
            break;
        case ATTACK:
            m_pFrameKey = L"Boss2_Attack";
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 625;
            //m_tFrame.bRepeat = false;

            m_AttackEnd = true;
            break;
        }
    }
}

void CHemisphere::Change_State()
{
    m_eCurState = ATTACK;
    Pattern1();
}

void CHemisphere::Pattern1()
{
    m_pFrameKey = L"Boss2_Attack";
    //�ش� ��������Ʈ �ݺ��ƴ� ����ؾ���!!!!!!!!!!!!
    m_tFrame.bRepeat = false;
    //���� �Ѿ� �����ڵ�(�Ѿ� Ŭ���� �����ʿ�)
    cout << "�ܼ� ���� ���� Ȯ�ο�" << endl;
    //Create_three_Bullet<CMonsterBullet1>();
    //ObjMgr->Add_Object(OBJ_BOSSMONSTER, CAbstractFactory<CGreenBoss>::Create(m_tInfo.fX-20.f, m_tInfo.fY));
    ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create(m_tInfo.fX, m_tInfo.fY-50.f));
    ObjMgr->Add_Object(OBJ_MONSTER, CAbstractFactory<CBladeMonster>::Create(m_tInfo.fX, m_tInfo.fY + 50.f));
    Create_three_Bullet<CMonsterBullet1>();
    m_tInfo.fCX = 68.f;
    m_tInfo.fCY = 68.f;
}

void CHemisphere::Pattern2()
{
}

void CHemisphere::Motion_Change()
{
    if (m_ePreState != m_eCurState)
    {
        switch (m_eCurState)
        {
        case CHemisphere::IDLE:
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 100;
            break;
        case CHemisphere::ATTACK:

            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 625;
            break;

        }
    }
    m_ePreState = m_eCurState;
}
