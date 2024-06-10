#include "ObjMgr.h"
#include "CollisionMgr.h"
#include "stdafx.h"
#include "EventDefine.h"
CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
	dwSaveTime = GetTickCount();
}

CObjMgr::~CObjMgr()
{
    Release();

}

CObj* CObjMgr::Get_Target(OBJ_ID eID, CObj* pObj)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;

	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		if (Src->Get_Dead())
			continue;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}

	}

	return pTarget;

}
CObj* CObjMgr::Get_Target_Within_Certain_Distance(OBJ_ID eID, CObj* pObj, float distance)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;

	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		if (Src->Get_Dead())
			break;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

		if (fDiagonal < distance&&(pObj->Get_Info().fX > Src->Get_Info().fX))
		{
			if ((!pTarget) || (fDistance > fDiagonal))
			{
				pTarget = Src;
				fDistance = fDiagonal;
			}
		}
		else
		{
			return nullptr;
		}
	}

	return pTarget;
}
CObj* CObjMgr::Get_Near_Target_BossMonster_Monster(OBJ_ID eID, OBJ_ID eID2, CObj* pObj)
{
	if (m_ObjList[eID].empty()&&m_ObjList[eID2].empty())
		return nullptr;

	CObj* pTarget = nullptr;

	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		if (Src->Get_Dead())
			continue;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}

	}
	for (auto& Src : m_ObjList[eID2])
	{
		if (Src->Get_Dead())
			continue;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}

	}
	return pTarget;
}
void CObjMgr::Delete_ID(OBJ_ID eID)
{
	for (auto& pObj : m_ObjList[eID])
		Safe_Delete(pObj);

	m_ObjList[eID].clear();
}

void CObjMgr::Delete_All()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
			Safe_Delete(pObj);

		m_ObjList[i].clear();
	}
}

void CObjMgr::Add_Object(OBJ_ID eID, CObj* pObj)
{
	if (OBJ_END <= eID || nullptr == pObj)
		return;

	m_ObjList[eID].push_back(pObj);
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
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYERBULLET], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PETBULLET], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYERBULLET], m_ObjList[OBJ_BOSSMONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PETBULLET], m_ObjList[OBJ_BOSSMONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ITEM]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_BOMB_ITEM]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_MONSTERBULLET],m_ObjList[OBJ_PLAYER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_BOSSMONSTER]);
	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER]);
	if (dwSaveTime+300<GetTickCount())
	{
		if (!m_ObjList[OBJ_PLAYERBOMB].empty())
		{
			CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYERBOMB], m_ObjList[OBJ_BOSSMONSTER]);
			CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYERBOMB], m_ObjList[OBJ_MONSTER]);
		}
		dwSaveTime = GetTickCount();
	}
	////오브젝트 bHit변수가 true일때만 플레이어 충돌검사
	//if (m_ObjList[OBJ_PLAYER].front()->Get_m_bCanHit())
	//{
	//	m_ObjList[OBJ_PLAYER].front()->Set_m_bCanHit(false);
	//	
	//}
}

void CObjMgr::Render(HDC hDC)
{
	/*for (size_t i = 0; i < RENDER_END; ++i)
	{
		m_RenderList[i].sort([](CObj* Dst, CObj* Src)->bool
			{
				return Dst->Get_Info().fY < Src->Get_Info().fY;
			});
		for (auto& pObj : m_RenderList[i])
			pObj->Render(hDC);
		m_RenderList[i].clear();
	}*/

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(hDC);
		}
	}

}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}

}
