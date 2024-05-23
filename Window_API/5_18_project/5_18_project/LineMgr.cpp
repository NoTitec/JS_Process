#include "LineMgr.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{

}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	LINEPOINT	tPoint[8] = {
		{ 100.f, 450.f },
		{ 300.f, 450.f },
		{ 500.f, 250.f },
		{ 700.f, 250.f },
		{100.f,150.f},
		{300.f,150.f},
		{100.f,350.f},
		{300.f,250.f}
	};

	m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
	m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
	m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
	m_LineList.push_back(new CLine(tPoint[4], tPoint[5]));
	m_LineList.push_back(new CLine(tPoint[6], tPoint[7]));
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

bool CLineMgr::Collision_Line(float fX, float fY,float* pY)
{
	if (m_LineList.empty())
		return false;
	
	CLine* pTarget = nullptr;
	float f_closestY = FLT_MAX;
	for (auto& pLine : m_LineList)
	{
		//�÷��̾� x ��ǥ�� �� x��ǥ �����ΰ��
		if (fX >= pLine->Get_Info().LeftPoint.fX &&
			fX <= pLine->Get_Info().RightPoint.fX)
		{
			//�ڱ����� y ���� �� y�� �� �Ʒ��� �ִ¼��ΰ��
			float x1t = pLine->Get_Info().LeftPoint.fX;
			float y1t = pLine->Get_Info().LeftPoint.fY;
			float x2t = pLine->Get_Info().RightPoint.fX;
			float y2t = pLine->Get_Info().RightPoint.fY;
			float tmpfY = ((y2t - y1t) / (x2t - x1t)) * (fX - x1t) + y1t;
			//�÷��̾� x���� ���� y�� �÷��̾�y���� ũ�� �÷��̾� x���� ���� y�� �� �Ÿ����� �������
			//if (tmpfY >= fY&&tmpfY<=f_closestY)
			if(tmpfY>=fY-10.f&& tmpfY <= f_closestY)
			{
				pTarget = pLine;
				f_closestY = tmpfY;
			}
			
		}
	}
	if (!pTarget)
		return false;
	
	float x1 = pTarget->Get_Info().LeftPoint.fX;
	float y1 = pTarget->Get_Info().LeftPoint.fY;
	float x2 = pTarget->Get_Info().RightPoint.fX;
	float y2 = pTarget->Get_Info().RightPoint.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
	return true;
	
	
}
