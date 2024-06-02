#include "UIMgr.h"
#include "stdafx.h"
#include "EventDefine.h"

CUIMgr* CUIMgr::m_pInstance = nullptr;

CUIMgr::CUIMgr()
{
}

CUIMgr::~CUIMgr()
{
	Release();

}

void CUIMgr::Delete_ID(UI_ID eID)
{
	for (auto& pUI : m_UIList[eID])
		Safe_Delete(pUI);

	m_UIList[eID].clear();
}

void CUIMgr::Add_UI(UI_ID eID, CUI* pUI)
{
	if (UI_END <= eID || nullptr == pUI)
		return;

	m_UIList[eID].push_back(pUI);
}

void CUIMgr::Update()
{
	for (size_t i = 0; i < UI_END; ++i)
	{
		for (auto iter = m_UIList[i].begin(); iter != m_UIList[i].end();)
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CUI*>(*iter);
				iter = m_UIList[i].erase(iter);
			}
			else
				++iter;

		}
	}
}

void CUIMgr::Late_Update()
{
	for (size_t i = 0; i < UI_END; ++i)
	{
		for (auto iter = m_UIList[i].begin(); iter != m_UIList[i].end(); ++iter)
		{
			(*iter)->Late_Update();

			if (m_UIList[i].empty())
				break;
		}
	}
}

void CUIMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < UI_END; ++i)
	{
		for (auto iter = m_UIList[i].begin(); iter != m_UIList[i].end(); ++iter)
		{
			(*iter)->Render(hDC);
		}
	}
}

void CUIMgr::Release()
{
	for (size_t i = 0; i < UI_END; ++i)
	{
		for_each(m_UIList[i].begin(), m_UIList[i].end(), Safe_Delete<CUI*>);
		m_UIList[i].clear();
	}
}
