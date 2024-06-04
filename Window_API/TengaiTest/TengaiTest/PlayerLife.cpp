#include "PlayerLife.h"
#include "EventDefine.h"
#include "Player.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
CPlayerLife::CPlayerLife()
{
}

CPlayerLife::~CPlayerLife()
{
}

void CPlayerLife::Initialize()
{
    m_tInfo.fCX = 16.f;
    m_tInfo.fCY = 14.f;
    m_eRender = RENDER_UI;

}

int CPlayerLife::Update()
{
    //__super::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayerLife::Late_Update()
{
	m_iPlayerLifeCount = m_pOwnerObject->Get_LifeCount();
	//__super::Move_Frame();
}

void CPlayerLife::Render(HDC hDC)
{
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tInfo.fX,
		m_tInfo.fY+iScrollY,
		(int)m_tInfo.fCX*5,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX*m_iPlayerLifeCount,
		(int)m_tInfo.fCY,
		RGB(255, 0, 152));
}

void CPlayerLife::Release()
{
}
