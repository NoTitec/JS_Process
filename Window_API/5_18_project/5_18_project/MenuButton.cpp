#include "MenuButton.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "stdafx.h"

CMenuButton::CMenuButton() : m_iDrawID(0)
{
}

CMenuButton::~CMenuButton()
{
    Release();

}

void CMenuButton::Initialize()
{
    m_tInfo.fCX = 150.f;
    m_tInfo.fCY = 150.f;
}

int CMenuButton::Update()
{
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMenuButton::Late_Update()
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"Start", m_pFrameKey))
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE);

			//else if (!lstrcmp(L"Edit", m_pFrameKey))
			//	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_EDIT);

			else if (!lstrcmp(L"Exit", m_pFrameKey))
				DestroyWindow(g_hWnd);

			return;
		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CMenuButton::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left,
		m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		m_iDrawID * (int)m_tInfo.fCX,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));
}

void CMenuButton::Release()
{
}
