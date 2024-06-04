#include "MikoPet.h"
#include "Player.h"
#include "EventDefine.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "MikoPetBasicBullet.h"
CMikoPet::CMikoPet()
{
}

CMikoPet::~CMikoPet()
{
    Release();
}

void CMikoPet::Initialize()
{
    m_eID = OBJ_PET;
    m_tInfo.fCX = 30.f;
    m_tInfo.fCY = 20.f;
    m_fSpeed = 0.f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 3;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 200;
    m_pFrameKey = L"MikoPet";

    m_dwBulletGenarateTime = GetTickCount();
    m_dwBulletGenarateSpeed = 300;
}

int CMikoPet::Update()
{
    m_tInfo.fX = dynamic_cast<CPlayer*>(m_pTarget)->Get_PetPoint().x;
    m_tInfo.fY = dynamic_cast<CPlayer*>(m_pTarget)->Get_PetPoint().y;
    __super::Update_Rect();
    Create_Basic_Bullet();
    return OBJ_NOEVENT;
}

void CMikoPet::Late_Update()
{
    __super::Move_Frame();
}

void CMikoPet::Render(HDC hDC)
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

void CMikoPet::OnHit(CObj* _pObj)
{
}

void CMikoPet::Release()
{
}

void CMikoPet::Create_Basic_Bullet()
{
    if (m_dwBulletGenarateTime + m_dwBulletGenarateSpeed < GetTickCount())
    {
        ObjMgr->Add_Object(OBJ_PETBULLET, CAbstractFactory<CMikoPetBasicBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));
        m_dwBulletGenarateTime = GetTickCount();
    }
}
