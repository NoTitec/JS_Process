#include "StartButton.h"
#include "EventDefine.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
CStartButton::CStartButton()
{
}

CStartButton::~CStartButton()
{
    Release();
}

void CStartButton::Initialize()
{
    m_tInfo.fCX = 300.f;
    m_tInfo.fCY = 62.f;
    m_eRender = RENDER_UI;
}

int CStartButton::Update()
{
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CStartButton::Late_Update()
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"StartButton", m_pFrameKey))
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_MENU);

			return;
		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CStartButton::Render(HDC hDC)
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
		RGB(0, 0, 0));
}

void CStartButton::Release()
{
}
