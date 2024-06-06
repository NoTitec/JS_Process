#include "PlayerDeadEffect.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "EventDefine.h"
#include "SoundMgr.h"
CPlayerDeadEffect::CPlayerDeadEffect()
{
}
CPlayerDeadEffect::~CPlayerDeadEffect()
{
    Release();
}
void CPlayerDeadEffect::Initialize()
{
    SoundMgr->StopSound(SOUND_PLAYER_BOMB);
    SoundMgr->PlaySoundW(L"koyori getting hit.wav", SOUND_PLAYER_BOMB, 0.5f);
    m_eID = OBJ_EFFECT;
    m_tInfo.fCX = 130.f;
    m_tInfo.fCY = 130.f;
    m_fSpeed = 0.f;
    //��Ʈ�̹��� ����
    m_tFrame.iFrameStart = -1;
    //��Ʈ�̹��� �ִ� ����
    m_tFrame.iFrameEnd = 6;
    //��Ʈ�̹��� ����
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 100;
    m_pFrameKey = L"PlayerDeadEffect";
}

int CPlayerDeadEffect::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayerDeadEffect::Late_Update()
{
    __super::Move_Frame_once_and_Destroy_self();
}

void CPlayerDeadEffect::Render(HDC hDC)
{
    int iScrollY = ScrollMgr->Get_ScrollY();

    HDC hMemDC = BmpMgr->Find_Img(m_pFrameKey);

    GdiTransparentBlt(hDC,
        m_tRect.left,
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

void CPlayerDeadEffect::Release()
{
}

void CPlayerDeadEffect::OnHit(CObj* _pObj)
{
}
