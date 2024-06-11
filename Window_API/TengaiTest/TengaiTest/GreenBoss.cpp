#include "GreenBoss.h"
#include "EventDefine.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "SoundMgr.h"
#include "AbstractFactory.h"
#include "PowerItem.h"
#include "BombItem.h"
#include "MonsterSpawnMgr.h"
#include "GreenBossDeadEffect.h"
CGreenBoss::CGreenBoss()
{
}

CGreenBoss::~CGreenBoss()
{
    Release();

}

void CGreenBoss::Initialize()
{
    m_eID = OBJ_BOSSMONSTER;
    m_tInfo = { 600.f, WINCY / 2.f, 82.f, 72.f };
    m_iHp = 50;
    m_fSpeed = 1.f;
    //패턴시간제어
    m_fSaveTime = GetTickCount();
    m_fCoolTime = 1700.f;

    m_eCurState = IDLE;
    m_ePattern = BOSS_PATTERN_END;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 3;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 200;
    m_pFrameKey = L"GreenBoss_Idle";
    m_tFrame.bRepeat = true;
}

int CGreenBoss::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    //현재 패턴에따라 업데이트
    switch (m_eCurState)
    {
    case IDLE:
        //패턴상태때 다른패턴공격방지도들어가야함
        if ((m_fSaveTime + m_fCoolTime < GetTickCount()))
        {
            //내상태를 패턴상태로 전환하는함수
            Change_State();
            m_fSaveTime = GetTickCount();
            //m_fAngle = rand() % 360;
        }
        m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
        m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

        break;
    case ATTACK:
        switch (m_ePattern)
        {
        case ONEPATTERN:
            if (m_bMoveForward)
            {
                m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
                m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

                //printf("(%f, %f) \n", m_tInfo.fX, m_tInfo.fY);
                //printf("<%d, %d> \n", m_Pattern1EndPoint.x, m_Pattern1EndPoint.y);
                //정밀도 문제로 정수형으로 형변환해야 오류 안생김
                if(abs(m_Pattern1EndPoint.x-(int)m_tInfo.fX)<20&& abs(m_Pattern1EndPoint.y - (int)m_tInfo.fY)<20)
                //if ((int)m_tInfo.fX == m_Pattern1EndPoint.x && (int)m_tInfo.fY == m_Pattern1EndPoint.y)
                {
                    m_bMoveForward = false;
                }
            }
            else
            {
                m_tInfo.fX += cos(m_fAngle * PI / 180.f) * -m_fSpeed;
                m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * -m_fSpeed;
                if (abs(m_Pattern1StartPoint.x - (int)m_tInfo.fX) < 20 && abs(m_Pattern1StartPoint.y - (int)m_tInfo.fY)<20)
                //if ((int)m_tInfo.fX == m_Pattern1StartPoint.x && (int)m_tInfo.fY == m_Pattern1StartPoint.y)
                {
                    //m_bMoveForward = true;
                    SoundMgr->StopSound(SOUND_BOSS_PATTERN1SOUND);
                    Set_State_Idle();
                }
            }
            break;
        case TWOPATTERN:
            break;
        }
        break;
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CGreenBoss::Late_Update()
{
    Motion_Change();
    if ((m_HitFrameSaveTime + 200 < GetTickCount()))
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"GreenBoss_Idle";
            m_tFrame.bRepeat = true;
            break;
        case ATTACK:
            m_pFrameKey = L"Boss_Attack_Pattern1";
            m_tFrame.bRepeat = false;
        }
        
    }
    __super::Move_Frame();
    /*if (m_eCurState == IDLE)
    {
        __super::Move_Frame();
    }
    else
    {
        Move_Frame_once_and_Return_Idle_State();
    }*/
    int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
    //상충돌이면 angle 180~360
    //하충돌이면 0~180
    //좌충돌이면 0~90or 270~360
    //우충돌이면 90~270
    // 좌충돌
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
        if (m_fAngle < 0) m_fAngle += 360;  // 정규화
    }
    // 우충돌
    if (m_tInfo.fX > 782) {
        m_fAngle = 90 + (rand() % 180);
        if (m_fAngle >= 360) m_fAngle -= 360;  // 정규화
    }
    // 상충돌
    if (m_tInfo.fY + iScrollY < 18) {
        m_fAngle = 180 + (rand() % 180);
        if (m_fAngle < 0) m_fAngle += 360;  // 정규화
    }
    // 하충돌
    if (m_tInfo.fY + iScrollY > 582) {
        m_fAngle = rand() % 180;
        if (m_fAngle >= 360) m_fAngle -= 360;  // 정규화
    }
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
    ObjMgr->Add_Object(OBJ_ITEM, CAbstractFactory<CPowerItem>::Create(m_tInfo.fX, m_tInfo.fY));
    ObjMgr->Add_Object(OBJ_BOMB_ITEM, CAbstractFactory<CBombItem>::Create(m_tInfo.fX, m_tInfo.fY));
    ObjMgr->Add_Object(OBJ_EFFECT,CAbstractFactory<CGreenBossDeadEffect>::Create(m_tInfo.fX,m_tInfo.fY));
    MonsterSpawnMgr->Set_BossMonsterDead();
}

void CGreenBoss::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYERBOMB:
        cout << "bombattacked" << endl;
    case OBJ_PLAYERBULLET:
        m_HitFrameSaveTime = GetTickCount();
        --m_iHp;
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"GreenBoss_Idle_White";
            m_tFrame.bRepeat = false;
            break;
        case ATTACK:
            m_pFrameKey = L"Boss_Attack_Pattern1_White";
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
            m_pFrameKey = L"GreenBoss_Idle_White";
            m_tFrame.bRepeat = false;
            break;
        case ATTACK:
            m_pFrameKey = L"Boss_Attack_Pattern1_White";
            m_tFrame.bRepeat = false;
            break;
        }
        if (m_iHp == 0)
            Set_Dead();
        break;
    }
}

void CGreenBoss::On_Motion_End()
{
    if (m_tFrame.bRepeat != true)
    {
        switch (m_eCurState)
        {
        case IDLE:
            m_pFrameKey = L"GreenBoss_Idle";
            m_tFrame.iFrameStart = 0;
            m_tFrame.iFrameEnd = 3;
            m_tFrame.iMotion = 0;
            m_tFrame.dwTime = GetTickCount();
            m_tFrame.dwSpeed = 200;
            m_tFrame.bRepeat = true;
            break;
        }
    }
}

//패턴쿨타임&&idle상태일때만 진입
void CGreenBoss::Change_State()
{
    m_eCurState = ATTACK;

    int irandomnumber = 0;

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
    SoundMgr->PlaySoundW(L"duende verde.wav",SOUND_BOSS_PATTERN1SOUND,0.2f);
    m_pFrameKey = L"Boss_Attack_Pattern1";
    m_eCurState = ATTACK;
    m_ePattern = ONEPATTERN;
    m_tInfo.fCX = 108.f;
    m_tInfo.fCY = 92.f;
    m_Pattern1StartPoint.x = m_tInfo.fX;
    m_Pattern1StartPoint.y = m_tInfo.fY;
    m_fSpeed = 8.f;
    m_bMoveForward = true;
    m_pTarget = ObjMgr->Get_Target(OBJ_PLAYER, this);
    if (m_pTarget)
    {
        float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

        fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
        fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

        fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

        fRadian = acos(fWidth / fDiagonal);

        if (m_pTarget->Get_Info().fY > m_tInfo.fY)
            fRadian = 2 * PI - fRadian;

        m_fAngle = fRadian * 180.f / PI;
    }
    m_Pattern1EndPoint.x = (int)(m_Pattern1StartPoint.x + cos(m_fAngle * PI / 180.f) * 500.f);
    m_Pattern1EndPoint.y = (int)(m_Pattern1StartPoint.y - sin(m_fAngle * PI / 180.f) * 500.f);

}

void CGreenBoss::Pattern2()
{
    //리소스 작업하고 추가
    m_pFrameKey = L"";
    m_eCurState = ATTACK;
    m_ePattern = TWOPATTERN;
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
                m_tFrame.iFrameEnd = 6;
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

void CGreenBoss::Move_Frame_once_and_Return_Idle_State()
{
    if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
    {
        ++m_tFrame.iFrameStart;

        if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
            Set_State_Idle();

        m_tFrame.dwTime = GetTickCount();
    }
}
