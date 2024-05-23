#include "stdafx.h"
#include "PHJ_Monster2.h"
#include "RenderMgr.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
#include "PHJ_LineMgr.h"

CPHJ_Monster2::CPHJ_Monster2()
{
}

CPHJ_Monster2::~CPHJ_Monster2()
{
	Release();
}

void CPHJ_Monster2::Initialize()
{
    int RandX = (rand() % 400) + 200;
    int iScrollX = (int)SCROLL.Get_ScrollX();
    m_tInfo = { (float)(RandX)-iScrollX, WINCY, 150.f, 200.f };
    m_fSpeed = 8.f;
    m_eID = PHJ_MONSTER;
    m_fJumptimer = 0.f;
    m_iHp = 10000; // ¸ø Á×ÀÓ
}

int CPHJ_Monster2::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    m_fJumptimer += 0.2f;
    m_tInfo.fY = m_tInfo.fY - ((m_fSpeed * 3 * m_fJumptimer) - (9.8f * m_fJumptimer * m_fJumptimer * 0.5f));
   
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPHJ_Monster2::Late_Update()
{
    if (m_tInfo.fY > WINCY) // ¹Ù´ÚÀ¸·Î ´Ù½Ã µé¾î°¡¸é »ç¸Á
        m_bDead = true;
}

void CPHJ_Monster2::Render(HDC hDC)
{
    RECT rect = m_tRect;
    int iScrollX = (int)SCROLL.Get_ScrollX();
    rect.left += iScrollX;
    rect.right += iScrollX;
    RENDER.DrawEllipse(rect);
}

void CPHJ_Monster2::Release()
{

}

void CPHJ_Monster2::OnHit(CObj* _pObj)
{
}
