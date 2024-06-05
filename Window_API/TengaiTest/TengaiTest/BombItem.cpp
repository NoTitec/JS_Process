#include "BombItem.h"
#include "EventDefine.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
CBombItem::CBombItem()
{
}

CBombItem::~CBombItem()
{
    Release();
}

void CBombItem::Initialize()
{
    m_eID = OBJ_BOMB_ITEM;
    //m_tInfo = { 400.f, WINCY / 3.f, 36.f, 26.f };
    m_tInfo.fCX = 36.f;
    m_tInfo.fCY = 26.f;
    m_fSpeed = 3.f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 9;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 80;
    m_pFrameKey = L"BombItem";
    m_fAngle = rand() % 360;
}

int CBombItem::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
    m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CBombItem::Late_Update()
{
    int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
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

void CBombItem::Render(HDC hDC)
{
    int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

    GdiTransparentBlt(hDC,
        m_tRect.left ,
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

void CBombItem::Release()
{
}

void CBombItem::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYER:
        Set_Dead();
        break;
    }
}
