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
	//�÷��̾��� m_pBullet ����Ʈ�� maingame�� �����ϴ� m_ObjList[OBJ_PLAYER] �ּ� set�ϱ�
	//�� �Ŵ����� �Ƹ���?
	//obj�� �޵����� obj�Ŵ����� ���µ� ���Ŵ����� ��������ϴ°� ������?
	// 
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Shield(&m_ObjList[OBJ_SHIELD]);
	// 
	//// ���콺 (���� ����Ʈ�� �������� ��ü Ŭ�����̸� �߸��� ����)
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, CAbstractFactory<CMouse>::Create());

	//�ڽ���
	/*for (int i = 0; i < 3; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BOX, CAbstractFactory<CBox>::Create(float(rand() % WINCX), float(rand() % WINCY)));
	}*/
	//// ����
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

	//// ��Ʈ ���

	//TCHAR	szBuf[32] = L"";

	//// wsprintf : �Ҽ��� �ڸ����� ��� �Ұ���, winapi ���̺귯������ ����
	// wsprintf(szBuf, L"Bullet : %d", m_ObjList[OBJ_BULLET].size());
	////swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ ���̺귯������ ����(��� ���� ���ڸ� ����)
	//TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));

	//FPS ���
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
