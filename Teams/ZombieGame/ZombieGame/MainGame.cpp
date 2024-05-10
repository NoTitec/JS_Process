#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Zombie.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CZombieMgr.h"
#include "ItemMgr.h"

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
	m_DC = GetDC(g_hWnd);
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);

}

void CMainGame::Update()
{	
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();
			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	CCollisionMgr::Collide_Item(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER]);
	CZombieMgr::Create_Zombie(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front());
	CItemMgr::Create_Item(&m_ObjList[OBJ_ITEM]);
}

void CMainGame::Render()
{
	++m_iFps;
	::Rectangle(m_DC, 0, 0, WINCX, WINCY);
	
	HBRUSH greyBrush = CreateSolidBrush(RGB(127, 125, 119));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(m_DC, greyBrush);
	::Rectangle(m_DC, 0, 0, WINCX, WINCY);
	::SelectObject(m_DC, oldBrush);
	::DeleteObject(greyBrush);
	

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_DC);
		}
	}
}

void CMainGame::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
	ReleaseDC(g_hWnd, m_DC);
}
