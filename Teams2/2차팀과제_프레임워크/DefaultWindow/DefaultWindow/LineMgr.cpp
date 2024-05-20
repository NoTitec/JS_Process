#include "stdafx.h"
#include "LineMgr.h"
#include "RenderMgr.h"

CLineMgr*	CLineMgr::m_pInstance = nullptr;
CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	LINEPOINT	tPoint[4] = {
		{ 100.f, 450.f },
		{ 300.f, 450.f },
		{ 500.f, 250.f },
		{ 700.f, 250.f }
	};

	m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
	m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
	m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
}

void CLineMgr::Render(HDC hDC)
{
	for (auto& Line : m_LineList)
		Line->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

bool CLineMgr::Collision_Line(float fX, float* pY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTarget = nullptr;

	for (auto& pLine : m_LineList)
	{
		if (fX >= pLine->Get_Info().tLeft.fX &&
			fX <= pLine->Get_Info().tRight.fX)
		{
			pTarget = pLine;
		}
	}

	if (!pTarget)
		return false;

	float		x1 = pTarget->Get_Info().tLeft.fX;
	float		y1 = pTarget->Get_Info().tLeft.fY;
	float		x2 = pTarget->Get_Info().tRight.fX;
	float		y2 = pTarget->Get_Info().tRight.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;

	return true;
}
