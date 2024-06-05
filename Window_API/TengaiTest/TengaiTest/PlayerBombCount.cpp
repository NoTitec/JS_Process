#include "PlayerBombCount.h"
#include "EventDefine.h"
#include "Player.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
CPlayerBombCount::CPlayerBombCount()
{
}
CPlayerBombCount::~CPlayerBombCount()
{
}
void CPlayerBombCount::Initialize()
{
    m_tInfo.fCX = 18.f;
    m_tInfo.fCY = 20.f;
    m_eRender = RENDER_UI;
}

int CPlayerBombCount::Update()
{
    return OBJ_NOEVENT;
}

void CPlayerBombCount::Late_Update()
{
    CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pOwnerObject);
    m_iPlayerBombCount = pPlayer->Get_BombCount();
}

void CPlayerBombCount::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tInfo.fX,
		m_tInfo.fY,
		(int)m_tInfo.fCX * m_iPlayerBombCount,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX * m_iPlayerBombCount,
		(int)m_tInfo.fCY,
		RGB(255, 0, 212));
}

void CPlayerBombCount::Release()
{
}
