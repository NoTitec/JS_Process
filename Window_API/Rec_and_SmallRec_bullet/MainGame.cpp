#include "MainGame.h"
#include "Obj.h"
#include "CPlayer.h"
#include "Define.h"
CMainGame::CMainGame() :m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	//플레이어 생성
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_BulletList(&m_BulletList);
}

void CMainGame::Update()
{
	//프레임마다 플레이어정보업데이트
	m_pPlayer->Update();
	//프레임마다 총알 전부 갱신
	
	for (auto it = m_BulletList.begin(); it != m_BulletList.end();)
	{
		if ((*it)->Update()) {
			it = m_BulletList.erase(it);  // erase 함수는 삭제된 요소의 다음 요소를 가리키는 반복자를 반환
		}
		else {
			++it;  // Update가 0이 아니면 다음 요소로 이동
		}
	}
}

void CMainGame::Render()
{
	//프레임마다 가장 큰 배경그려주고
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	//그보다 100만큼 크기 작은 배경그려주고
	Rectangle(m_DC, 100,100, SMALLWINCX, SMALLWINCY);
	//플레이어 그리기
	m_pPlayer->Render(m_DC);
	//총알들 그리기
	for (auto& pBullet : m_BulletList)
		pBullet->Render(m_DC);
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);
	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	m_BulletList.clear();
	ReleaseDC(g_hWnd, m_DC);
}
