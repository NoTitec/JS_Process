#include "stdafx.h"
#include "ObjMgr.h"
#include "ZombieManager.h"
#include "CollisionManager.h"

//static 포인터는 외부 초기화 해야함
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

//찾을 타입아이디와 위치값 인자로 받아 해당 좌표와 가장가까운 오브젝트 반환함수
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
	//몬스터 플레이어 사각형충돌검출
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_PLAYER]);
	//좀비 총알 원형판정 삭제
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	//좀비 실드 충돌삭제
	//CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_SHIELD], m_ObjList[OBJ_ZOMBIE]);
	//좀비 플레이어 접촉시 삭제
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ZOMBIE]);

	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_ZOMBIE]);
	
	//CCollisionMgr::Collision_Rect(m_ObjList[OBJ_MOUSE], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
	//좀비 생성 매니저
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

	// 폰트 출력
	TCHAR	szBuf[32] = L"";
	// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	wsprintf(szBuf, L"Bullet : %d", (int)m_ObjList[OBJ_BULLET].size());
	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ 라이브러리에서 제공(모든 서식 문자를 지원)
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