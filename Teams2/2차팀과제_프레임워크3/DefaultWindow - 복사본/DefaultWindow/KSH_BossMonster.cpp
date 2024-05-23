#include "stdafx.h"
#include "KSH_BossMonster.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "KSH_MonsterBullet.h"
CKSH_BossMonster::CKSH_BossMonster()
{
}

CKSH_BossMonster::~CKSH_BossMonster()
{
    Release();
}

void CKSH_BossMonster::OnHit(CObj* _pObj)
{
    if (_pObj->Get_ID() == OBJ_PLAYER_BULLET)
    {
        _pObj->Set_Dead();
    }
}

void CKSH_BossMonster::Initialize()
{
    m_tInfo.fCX = 300.f;
    m_tInfo.fCY = 300.f;

    m_fSpeed = 3.f;
    //패턴시간제어
    m_fSaveTime = GetTickCount();
    m_fCoolTime = 3000.f;

    Set_ID(OBJ_MONSTER);

    boss_state = IDLE;
}

int CKSH_BossMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    //패턴상태때 다른패턴공격방지도들어가야함
    if ((GetTickCount() - m_fSaveTime > m_fCoolTime ) && boss_state==IDLE)
    {
        //내상태를 패턴상태로 전환하는함수
        Change_State();
        m_fSaveTime = GetTickCount();
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CKSH_BossMonster::Late_Update()
{
}

void CKSH_BossMonster::Render(HDC hDC)
{
    int	iScrollX = (int)SCROLL.Get_ScrollX();
    HDC hMemDC = BMP.Find_Img(L"KSH_BossMonster");
    GdiTransparentBlt(hDC,
        m_tRect.left+ iScrollX,
        m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        0, 0,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(255, 255, 255));
}

void CKSH_BossMonster::Release()
{
}

void CKSH_BossMonster::Change_State()
{
    //enum BOSSSTATE { IDLE, ATTACK, BOSS_ST_END };
    //enum PATTERN { ONEPATTERN, TWOPATTERN, BOSS_PATTERN_END };
    boss_state = ATTACK;

    //int irandomnumber = rand() % 2;
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

void CKSH_BossMonster::Pattern1()
{
    OBJ.Add_Object(OBJ_MONSTER_BULLET, CAbstractFactory<CKSH_MonsterBullet>::Create(m_tInfo.fX,m_tInfo.fY,DIR_UP));
    OBJ.Add_Object(OBJ_MONSTER_BULLET, CAbstractFactory<CKSH_MonsterBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_DOWN));
    OBJ.Add_Object(OBJ_MONSTER_BULLET, CAbstractFactory<CKSH_MonsterBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));
    OBJ.Add_Object(OBJ_MONSTER_BULLET, CAbstractFactory<CKSH_MonsterBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));


    boss_state = IDLE;
}

void CKSH_BossMonster::Pattern2()
{

    boss_state = IDLE;
}

