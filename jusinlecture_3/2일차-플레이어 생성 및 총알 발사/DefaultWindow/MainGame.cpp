#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame() : m_pPlayer(nullptr), m_dwTime(GetTickCount()), m_iFps(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{

	m_DC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
}

void CMainGame::Update()
{
	m_pPlayer->Update();

	for (auto& pBullet : m_BulletList)
		pBullet->Update();
}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);

	for (auto& pBullet : m_BulletList)
		pBullet->Render(m_DC);

	// 폰트 출력

	//TCHAR	szBuf[32] = L"";

	// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	// wsprintf(szBuf, L"Bullet : %d", m_BulletList.size());
//
	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ 라이브러리에서 제공(모든 서식 문자를 지원)
	//TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));


	// 1. dc 
	// 2-3. x,y 좌표
	// 4. 문자열 버퍼의 첫 주소
	// 5. 문자열 버퍼의 크기

	// RECT	rc{ 100, 100, 200, 200 };
	// lstrcpy(szBuf, L"Jusin");
	// DrawText(m_DC, szBuf, lstrlen(szBuf), &rc, DT_CENTER);

	// fps 출력

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFps);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFps = 0;
		m_dwTime = GetTickCount();
	}
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);

	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	m_BulletList.clear();

	ReleaseDC(g_hWnd, m_DC);

	
}
