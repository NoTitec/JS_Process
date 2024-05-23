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

    if (m_bFall) // ���� �� 
    {
        float fChangeY; // ����, ���� ȿ�� ����� �� y ��
        float fLineY = 0.f; // x�� �������� ���� ���� �� ���� y ��
        bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // �� �Ʒ� ������ �ִ��� üũ
        m_fFalltimer += 0.2f;
        fChangeY = m_tInfo.fY + ((4.8f * m_fFalltimer * m_fFalltimer) * 0.5f); // ���� ����
        if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // ���� O, ���� O, ���� ���� �ִ� ���� �� �Ʒ��� �������� �ߴ� & ����
        {
            m_bFall = false;
            m_fFalltimer = 0.f;
            m_tInfo.fY = fLineY;
        }
        else
            m_tInfo.fY = fChangeY;
    }
    else // ���� ����
    {
        if (m_bMove)
            m_tInfo.fX -= m_fSpeed;
        else
            m_tInfo.fX += m_fSpeed;
        float fLineY = 0.f; // x�� �������� ���� ���� �� ���� y ��
        bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // �� �Ʒ� ������ �ִ��� üũ
        if (!bLineCol || fLineY - m_tInfo.fY > 30.f) // �����̸� �������� ���
        {
            if (m_bMove)
                m_tInfo.fX += m_fSpeed, m_bMove = false;
            else
                m_tInfo.fX -= m_fSpeed, m_bMove = true;
        }
        else // �������� ���� ������ ����Ž
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
