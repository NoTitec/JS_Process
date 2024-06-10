#include "GreenBossDeadEffect.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "EventDefine.h"
#include "SoundMgr.h"
CGreenBossDeadEffect::CGreenBossDeadEffect()
{
}

CGreenBossDeadEffect::~CGreenBossDeadEffect()
{
    Release();
}

void CGreenBossDeadEffect::Initialize()
{
    SoundMgr->StopSound(SOUND_BOSS_DEAD);
    SoundMgr->PlaySoundW(L"tengai-139 enemy death (3).wav", SOUND_BOSS_DEAD, 0.5f);
    m_eID = OBJ_EFFECT;
    m_tInfo.fCX = 128.f;
    m_tInfo.fCY = 128.f;
    m_fSpeed = 0.f;
    //비트이미지 가로
    m_tFrame.iFrameStart = -1;
    //비트이미지 최대 개수
    m_tFrame.iFrameEnd = 7;
    //비트이미지 세로
    m_tFrame.iMotion = 0;
    m_tFrame.dwTime = GetTickCount();
    m_tFrame.dwSpeed = 100;
    m_pFrameKey = L"GreenBossDeadEffect";
}

int CGreenBossDeadEffect::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CGreenBossDeadEffect::Late_Update()
{
    __super::Move_Frame_once_and_Destroy_self();

}

void CGreenBossDeadEffect::Render(HDC hDC)
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

void CGreenBossDeadEffect::Release()
{
}

void CGreenBossDeadEffect::OnHit(CObj* _pObj)
{
}
