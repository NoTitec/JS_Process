#include "PlayerHeadUI.h"
#include "EventDefine.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

#include "SceneMgr.h"
CPlayerHeadUI::CPlayerHeadUI()
{
}

CPlayerHeadUI::~CPlayerHeadUI()
{
}

void CPlayerHeadUI::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 20.f;
	m_eRender=RENDER_UI;
	//m_iDrawID = 0;
	//비트이미지 가로
	m_tFrame.iFrameStart = -1;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 3;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.dwSpeed = 300;
}

int CPlayerHeadUI::Update()
{
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayerHeadUI::Late_Update()
{
	m_tInfo.fX = m_pOwnerObject->Get_Info().fX;
	m_tInfo.fY = m_pOwnerObject->Get_Info().fY - 32.f;
	m_bShow = m_pOwnerObject->Get_HeadUIShow();
	__super::Move_Frame_one_cycle();
}

void CPlayerHeadUI::Render(HDC hDC)
{
	if (m_bShow == true)
	{
		int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
		HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

		GdiTransparentBlt(hDC,
			m_tRect.left,
			m_tRect.top + iScrollY,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDC,
			(int)m_tInfo.fCX * m_tFrame.iFrameStart,
			0,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			RGB(255, 0, 212));
	}
}

void CPlayerHeadUI::Release()
{
}
