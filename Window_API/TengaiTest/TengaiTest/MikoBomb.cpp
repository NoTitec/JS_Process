#include "MikoBomb.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "EventDefine.h"
#include "SoundMgr.h"
CMikoBomb::CMikoBomb()
{
}

CMikoBomb::~CMikoBomb()
{
    Release();
}

void CMikoBomb::Initialize()
{
    SoundMgr->StopSound(SOUND_PLAYER_BOMB);
    SoundMgr->PlaySoundW(L"koyorialt2.wav", SOUND_PLAYER_BOMB, 0.5f);
    m_eID = OBJ_PLAYERBOMB;
    m_tInfo.fCX = 160.f;
    m_tInfo.fCY = 160.f;
    m_fSpeed = 0.f;
    //��Ʈ�̹��� ����
    m_tFrame.iFrameStart = -1;
    //��Ʈ�̹��� �ִ� ����
    m_tFrame.iFrameEnd = 17;
    //��Ʈ�̹��� ����
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 150;
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
