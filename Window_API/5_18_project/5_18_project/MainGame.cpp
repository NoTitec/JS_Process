#include "MainGame.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "Box.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CMainGame::CMainGame() : m_dwTime(GetTickCount()), m_iFps(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	srand(unsigned(time(NULL)));

	m_DC = GetDC(g_hWnd);

	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_LOGO);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/maja2.bmp", L"Player");


	//m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	//플레이어의 m_pBullet 리스트에 maingame이 관리하는 m_ObjList[OBJ_PLAYER] 주소 set하기
	//선 매니저도 아마도?
	//obj는 메디에이터 obj매니저로 뺐는데 선매니저는 어떤식으로하는게 좋을까?
	// 
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Shield(&m_ObjList[OBJ_SHIELD]);
	// 
	//// 마우스 (생성 리스트랑 실제생성 객체 클래스이름 잘못줌 ㅅㅂ)
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, CAbstractFactory<CMouse>::Create());

	//박스들
	/*for (int i = 0; i < 3; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BOX, CAbstractFactory<CBox>::Create(float(rand() % WINCX), float(rand() % WINCY)));
	}*/
	//// 몬스터
	/*for (int i = 0; i < 5; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(float(rand() % WINCX), float(rand() % WINCY)));
	}*/

}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
	
}

void CMainGame::LateUpdate()
{
	CSceneMgr::Get_Instance()->Late_Update();
	CKeyMgr::Get_Instance()->Key_Update();
	CScrollMgr::Get_Instance()->Scroll_Lock();

}

void CMainGame::Render()
{
	++m_iFps;

	//Rectangle(m_DC, 0, 0, WINCX, WINCY);
	//Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");
	CSceneMgr::Get_Instance()->Render(hMemDC);

	BitBlt(m_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	//// 폰트 출력

	//TCHAR	szBuf[32] = L"";

	//// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	// wsprintf(szBuf, L"Bullet : %d", m_ObjList[OBJ_BULLET].size());
	////swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ 라이브러리에서 제공(모든 서식 문자를 지원)
	//TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));

	//FPS 출력
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
	CLineMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);
}
