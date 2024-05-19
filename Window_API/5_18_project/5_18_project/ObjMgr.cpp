#include "ObjMgr.h"
#include "CollisionMgr.h"

//Ŭ���� static �ɹ������� �ݵ�� �ܺμ� classname::�����̸�= �������� �ʱ�ȭ�ؾ���
CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
	m_DC = GetDC(g_hWnd);
}

CObjMgr::~CObjMgr()
{
	Release();
}

//����ü id�� ���� ��ü�� �޾� �����ϴ� �Լ�
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
	// ��Ʈ ���

	TCHAR	szBuf[32] = L"";

	//// wsprintf : �Ҽ��� �ڸ����� ��� �Ұ���, winapi ���̺귯������ ����
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

//eId ����Ʈ ������ pObj�� ���� ����� ��ü ��ȯ
CObj* CObjMgr::Get_Target(OBJ_ID eID, CObj* pObj)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;

	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		//Ÿ�� �׾����� �ٸ� Ÿ�� ã��
		if (Src->Get_Dead())
			continue;

		float		fWidth = pObj->Get_Info().fX - Src->Get_Info().fX;
		float		fHeight = pObj->Get_Info().fY - Src->Get_Info().fY;

		//Ÿ�ٰ� ���ǰŸ�
		float		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);
		//Ÿ�������Ͱ� null�̾ƴϸ� �����Ű�� null�̰� ���簡�尡��� �Ÿ� fDistance �� �������� Ÿ�ٺ��� ũ�� ���尡��� Ÿ���� ����
		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}

	}

	return pTarget;
}
