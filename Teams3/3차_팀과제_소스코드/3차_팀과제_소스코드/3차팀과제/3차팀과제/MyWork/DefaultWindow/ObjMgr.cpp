#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"
#include "ColMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{

}

CObjMgr::~CObjMgr()
{

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

			if (m_ObjList[i].empty())
				break;
		}
	}
	
	COLMGR->Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER]);
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < (int)OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
			pObj->Render(hDC);
	}
}

void CObjMgr::Delete_ID(OBJ_ID eID)
{
	for (auto& pObj : m_ObjList[eID])
		Safe_Delete(pObj);

	m_ObjList[eID].clear();
}


void CObjMgr::Add_Object(OBJ_ID eID, CObj* pObj)
{
	if (int(OBJ_END) <= int(eID) || nullptr == pObj)
		return;
	m_ObjList[int(eID)].push_back(pObj);
}
