#include "stdafx.h"
#include "ObjMgr.h"
#include "ZombieManager.h"
#include "CollisionManager.h"

//static �����ʹ� �ܺ� �ʱ�ȭ �ؾ���
CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Add_Object(OBJ_ID eID, CObj* pObj)
{
	if (OBJ_END <= eID || nullptr == pObj)
		return;

	m_ObjList[eID].push_back(pObj);
}

//ã�� Ÿ�Ծ��̵�� ��ġ�� ���ڷ� �޾� �ش� ��ǥ�� ���尡��� ������Ʈ ��ȯ�Լ�
CObj* CObjMgr::Get_Nearest_Object(OBJ_ID eID, float _fX, float _fY)
{
	CObj* NearestObj=nullptr;
	float fdistance=9999.f;
	for (auto iter = m_ObjList[OBJ_ZOMBIE].begin(); iter != m_ObjList[OBJ_ZOMBIE].end(); ++iter)
	{
		float fWidth = _fX - (*iter)->Get_Info().fX;
		float fHeight = _fY - (*iter)->Get_Info().fY;

		float fcurdistance=sqrt(fWidth * fWidth + fHeight * fHeight);
		if (fcurdistance < fdistance)
		{
			fdistance = fcurdistance;
			NearestObj = *iter;
		}
	}
	return NearestObj;
}
void CObjMgr::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CObjMgr::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}
	//���� �÷��̾� �簢���浹����
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_PLAYER]);
	//���� �Ѿ� �������� ����
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	//���� �ǵ� �浹����
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_SHIELD], m_ObjList[OBJ_ZOMBIE]);
	//���� �÷��̾� ���˽� ����
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ZOMBIE]);

	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	
	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_MOUSE], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
	//���� ���� �Ŵ���
	CZombieManager::Create_Zombie(&m_ObjList[OBJ_ZOMBIE], m_ObjList[OBJ_PLAYER].front());
}

void CObjMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(hDC);
		}
	}

	// ��Ʈ ���
	TCHAR	szBuf[32] = L"";
	// wsprintf : �Ҽ��� �ڸ����� ��� �Ұ���, winapi ���̺귯������ ����
	wsprintf(szBuf, L"Bullet : %d", (int)m_ObjList[OBJ_BULLET].size());
	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ ���̺귯������ ����(��� ���� ���ڸ� ����)
	TextOut(hDC, 50, 50, szBuf, lstrlen(szBuf));
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}