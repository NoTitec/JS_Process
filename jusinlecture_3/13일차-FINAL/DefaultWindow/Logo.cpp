#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"


CLogo::CLogo()
{
}


CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo/Logo.bmp", L"Logo");

	// MCIWndCreate : 멀티미디어를 재생하기 위한 윈도우를 생성하는 함수

	m_hVideo = MCIWndCreate(g_hWnd,		// 부모 윈도우 핸들
							nullptr,	// 인스턴스 핸들
							WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR,	// 윈도우 모양 설정
							L"../Video/Wildlife.wmv");		// 재생할 파일의 경로

	// 동영상 재생 크기를 설정
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	MCIWndPlay(m_hVideo);

}

int CLogo::Update()
{
	return 0;
}

void CLogo::Late_Update()
{
	if (MCIWndGetLength(m_hVideo) <= MCIWndGetPosition(m_hVideo) ||
		CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_MENU);
		return;
	}

}

void CLogo::Render(HDC hDC)
{
	// HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	// BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CLogo::Release()
{
	MCIWndClose(m_hVideo);
}
