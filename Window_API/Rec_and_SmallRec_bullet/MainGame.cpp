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

	//�÷��̾� ����
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_BulletList(&m_BulletList);
}

void CMainGame::Update()
{
	//�����Ӹ��� �÷��̾�����������Ʈ
	m_pPlayer->Update();
	//�����Ӹ��� �Ѿ� ���� ����
	
	for (auto it = m_BulletList.begin(); it != m_BulletList.end();)
	{
		if ((*it)->Update()) {
			it = m_BulletList.erase(it);  // erase �Լ��� ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
		}
		else {
			++it;  // Update�� 0�� �ƴϸ� ���� ��ҷ� �̵�
		}
	}
}

void CMainGame::Render()
{
	//�����Ӹ��� ���� ū ���׷��ְ�
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	//�׺��� 100��ŭ ũ�� ���� ���׷��ְ�
	Rectangle(m_DC, 100,100, SMALLWINCX, SMALLWINCY);
	//�÷��̾� �׸���
	m_pPlayer->Render(m_DC);
	//�Ѿ˵� �׸���
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
