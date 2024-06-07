#include "BladeMonster.h"
#include "EventDefine.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
CBladeMonster::CBladeMonster()
{

}

CBladeMonster::~CBladeMonster()
{
    Release();
}

void CBladeMonster::Initialize()
{
    m_eID = OBJ_MONSTER;
    //m_tInfo = {750.f,50.f,32.f,29.f};
    m_tInfo.fCX=32.f;
    m_tInfo.fCY = 29.f;
    m_iHp = 5;
    m_eDir = DIR_LEFT;
    m_fSpeed = 1.f;
    m_fmaxAngle = 0.1f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 7;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 100;
    m_pFrameKey = L"BladeMonster";
    
}

int CBladeMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;


    m_pTarget = ObjMgr->Get_Target_Within_Certain_Distance(OBJ_PLAYER,this,400.f);
    if (m_pTarget)
    {
        m_fSpeed = 2.f;
        float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

        fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
        fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

        fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

        fRadian = acos(fWidth / fDiagonal);

        if (m_pTarget->Get_Info().fY > m_tInfo.fY)
            fRadian = 2 * PI - fRadian;
        // 최대 허용 각도를 초과하지 않도록 조정
        if (m_fAngle > m_fmaxAngle) {
            m_fAngle = m_fmaxAngle;
        }
        else if (m_fAngle < -m_fmaxAngle) {
            m_fAngle = -m_fmaxAngle;
        }
        m_fAngle = fRadian * 180.f / PI;
        
        m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
        m_tInfo.fX -= m_fSpeed;
        m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

    }
    else
    {
        m_tInfo.fX -= m_fSpeed;
        //switch (m_eDir)
        //{
        //case DIR_LEFT:
        //    m_tInfo.fX -= m_fSpeed;
        //    break;
        //}
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CBladeMonster::Late_Update()
{
    int iScrollY = ScrollMgr->Get_ScrollY();

    //if (-20 >= m_tRect.left || WINCX <= m_tRect.right ||
    //    -20 >= m_tRect.top + iScrollY || WINCY <= m_tRect.bottom + iScrollY)
    //{
    //    m_bDead = true;
    //}
    __super::Move_Frame();
}

void CBladeMonster::Render(HDC hDC)
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

void CBladeMonster::Release()
{
}

void CBladeMonster::OnHit(CObj* _pObj)
{
    OBJ_ID pObj_ID = _pObj->Get_ID();
    switch (pObj_ID)
    {
    case OBJ_PLAYERBULLET:
        --m_iHp;
        if (m_iHp == 0)
            Set_Dead();
        break;
    case OBJ_PLAYERBOMB:
        cout << "bombattacked" << endl;
        --m_iHp;
        if (m_iHp == 0)
            Set_Dead();
        break;
    case OBJ_PETBULLET:
        --m_iHp;
        if (m_iHp == 0)
            Set_Dead();
        break;
    }
}
