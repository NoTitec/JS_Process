#include "MikoBomb.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "EventDefine.h"
CMikoBomb::CMikoBomb()
{
}

CMikoBomb::~CMikoBomb()
{
    Release();
}

void CMikoBomb::Initialize()
{
    m_eID = OBJ_PLAYERBOMB;
    m_tInfo.fCX = 160.f;
    m_tInfo.fCY = 160.f;
    m_fSpeed = 0.f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 8;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 300;
    m_pFrameKey = L"BigCircleKangiNoBolt";
}

int CMikoBomb::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CMikoBomb::Late_Update()
{
    Move_Frame_once_and_Destroy_self();
}

void CMikoBomb::Render(HDC hDC)
{
    int iScrollY = ScrollMgr->Get_ScrollY();

    HDC hMemDC = BmpMgr->Find_Img(m_pFrameKey);

    GdiTransparentBlt(hDC,
        m_tRect.left,
        m_tRect.top +iScrollY,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        (int)m_tInfo.fCX * m_tFrame.iFrameStart,
        (int)m_tInfo.fCY * m_tFrame.iMotion,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(255, 50, 231));
}

void CMikoBomb::Release()
{
}

void CMikoBomb::OnHit(CObj* _pObj)
{
}
