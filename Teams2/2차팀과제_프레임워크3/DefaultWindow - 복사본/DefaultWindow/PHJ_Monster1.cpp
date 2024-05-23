#include "stdafx.h"
#include "PHJ_Monster1.h"
#include "RenderMgr.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
#include "PHJ_LineMgr.h"
#include "PHJ_Bullet.h"

CPHJ_Monster1::CPHJ_Monster1()
{
}

CPHJ_Monster1::~CPHJ_Monster1()
{
    Release();
}

void CPHJ_Monster1::Initialize()
{
    int RandX = rand() % 800;
    int iScrollX = (int)SCROLL.Get_ScrollX();
    m_tInfo = { (float)(RandX) -iScrollX, 0.f, 70.f, 70.f};
    m_fSpeed = 5.f;
    m_eID = PHJ_MONSTER;
    m_bFall = true;
    m_fFalltimer = 0.f;
    m_bMove = false;
    m_iHp = 5;
}

int CPHJ_Monster1::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    if (m_bFall) // 낙하 중 
    {
        float fChangeY; // 낙하, 점프 효과 적용된 후 y 값
        float fLineY = 0.f; // x값 기준으로 발판 있을 때 계산된 y 값
        bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // 발 아래 라인이 있는지 체크
        m_fFalltimer += 0.2f;
        fChangeY = m_tInfo.fY + ((4.8f * m_fFalltimer * m_fFalltimer) * 0.5f); // 수직 낙하
        if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // 발판 O, 낙하 O, 발판 위에 있다 낙하 중 아래로 떨어지면 중단 & 복구
        {
            m_bFall = false;
            m_fFalltimer = 0.f;
            m_tInfo.fY = fLineY;
        }
        else
            m_tInfo.fY = fChangeY;
    }
    else // 지면 도착
    {
        if (m_bMove)
            m_tInfo.fX -= m_fSpeed;
        else
            m_tInfo.fX += m_fSpeed;
        float fLineY = 0.f; // x값 기준으로 발판 있을 때 계산된 y 값
        bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // 발 아래 라인이 있는지 체크
        if (!bLineCol || fLineY - m_tInfo.fY > 30.f) // 움직이면 떨어지는 경우
        {
            if (m_bMove)
                m_tInfo.fX += m_fSpeed, m_bMove = false;
            else
                m_tInfo.fX -= m_fSpeed, m_bMove = true;
        }
        else // 움직여도 발판 있으면 라인탐
        {
            m_tInfo.fY = fLineY;
        }
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPHJ_Monster1::Late_Update()
{
    if (m_iHp <= 0 || m_tInfo.fY > WINCY)
        m_bDead = true;
}

void CPHJ_Monster1::Render(HDC hDC)
{
    RECT rect = m_tRect;
    int iScrollX = (int)SCROLL.Get_ScrollX();
    rect.left += iScrollX;
    rect.right += iScrollX;
    RENDER.DrawEllipse(rect);
}

void CPHJ_Monster1::Release()
{

}

void CPHJ_Monster1::OnHit(CObj* _pObj)
{
    PHJ_ID ID = dynamic_cast<CPHJ_Obj*>(_pObj)->Get_ID();
    if (ID == PHJ_BULLET)
    {
        OWNER Own = dynamic_cast<CPHJ_Bullet*>(_pObj)->Get_Owner();
        if (Own == PLAYER)
            m_iHp--;
    }
}
