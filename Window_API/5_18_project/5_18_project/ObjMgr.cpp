#include "ObjMgr.h"
#include "CollisionMgr.h"

//클래스 static 맴버변수는 반드시 외부서 classname::변수이름= 형식으로 초기화해야함
CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
	m_DC = GetDC(g_hWnd);
}

CObjMgr::~CObjMgr()
{
	Release();
}

//열거체 id와 실제 객체를 받아 저장하는 함수
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
		}
	}
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_RectEx(m_ObjList[OBJ_BOX], m_ObjList[OBJ_PLAYER]);
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

	//// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	wsprintf(szBuf, L"Bullet : %d", m_ObjList[OBJ_BULLET].size());
	TextOut(m_DC, 50, 50, szBuf, lstrlen(szBuf));
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}

CObj* CObjMgr::Get_Player()
{
	return m_ObjList[OBJ_PLAYER].front();
}

//eId 리스트 원소중 pObj와 가장 가까운 객체 반환
CObj* CObjMgr::Get_Target(OBJ_ID eID, CObj* pObj)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;

	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		//타겟 죽었으면 다른 타겟 찾기
		if (Src->Get_Dead())
			continue;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		//타겟과 나의거리
		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);
		//타겟포인터가 null이아니면 종료시키고 null이고 현재가장가까운 거리 fDistance 가 지금현재 타겟보다 크면 가장가까운 타겟을 갱신
		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}

	}

	return pTarget;
}
