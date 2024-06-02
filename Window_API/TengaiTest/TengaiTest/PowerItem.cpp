#include "PowerItem.h"
#include "EventDefine.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
CPowerItem::CPowerItem()
{
}

CPowerItem::~CPowerItem()
{
    Release();

}

void CPowerItem::Initialize()
{
    m_eID = OBJ_ITEM;
    m_tInfo = { 400.f, WINCY / 3.f, 36.f, 26.f };
    m_fSpeed = 3.f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 15;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 80;
    m_pFrameKey = L"PowerItem";
    m_fAngle = rand() % 360;
}

int CPowerItem::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
    m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPowerItem::Late_Update()
{
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
    __super::Move_Frame();
}

void CPowerItem::Render(HDC hDC)
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

void CPowerItem::Release()
{
}

void CPowerItem::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYER:
        Set_Dead();
        break;
    }
}
