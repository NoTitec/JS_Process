#include "MainGame.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "Monster.h"
#include "Mouse.h"
#include "Box.h"
#include "KeyMgr.h"
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

	CLineMgr::Get_Instance()->Initialize();

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

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
	CObjMgr::Get_Instance()->Update();
	
}

void CMainGame::LateUpdate()
{
	CObjMgr::Get_Instance()->Late_Update();
	CKeyMgr::Get_Instance()->Key_Update();

}

void CMainGame::Render()
{
	++m_iFps;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	//Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);

	CLineMgr::Get_Instance()->Render(m_DC);

	//������ ���Ծ �׸��� ������ ����ȵǰ� �־��� ����
	CObjMgr::Get_Instance()->Render(m_DC);

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

	ReleaseDC(g_hWnd, m_DC);
}
