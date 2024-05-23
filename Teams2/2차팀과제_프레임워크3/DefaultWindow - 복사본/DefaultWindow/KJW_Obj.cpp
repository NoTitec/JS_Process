#include "stdafx.h"
#include "KJW_Obj.h"
#include "KJW_LineMgr.h"

void CKJW_Obj::KJW_Update_Rect()
{
	m_tRect.left = long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top = long(m_tInfo.fY - m_tInfo.fCY );
	m_tRect.right = long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom = long(m_tInfo.fY );
	
}

void CKJW_Obj::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < g_dwTime)
	{
		++m_tFrame.iFrameStart;

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		{
			if (m_tFrame.bRepeat)
				m_tFrame.iFrameStart = 0;
			else
			{
				OnMotionEnd();
				m_tFrame.iFrameStart = m_tFrame.iFrameEnd;
			}
		}

		m_tFrame.dwTime = g_dwTime;
	}
}

void CKJW_Obj::OnMotionEnd()
{
}



void CKJW_Obj::Change_Motion()
{
}

bool CKJW_Obj::Check_Front_Wall()
{
	float fNextXSolution = KJW_LINE.Get_Wall_X({ m_tInfo.fX  , m_tInfo.fY - m_fFootHeight }, m_fXSpd > 0);
	if (m_fXSpd > 0)
	{
		if (fNextXSolution < m_tInfo.fX + m_fXSpd)
		{
			return true;
		}
	}
	else
	{
		if (fNextXSolution > m_tInfo.fX + m_fXSpd)
		{
			return true;
		}
	}
	return false;
}

bool CKJW_Obj::Check_Front_Floor(float& _fYSol)
{
	_fYSol = KJW_LINE.Get_Floor_Y({ m_tInfo.fX + m_fXSpd , m_tInfo.fY + m_fYSpd - m_fFootHeight });
	if ((_fYSol - (m_tInfo.fY + m_fYSpd)) > m_fFootHeight)
	{
		return false;
		//m_bJump = true;
	}
	else
	{
		return true;
		//m_tInfo.fY = fNextYSolution;

	}
	return false;
}

bool CKJW_Obj::Check_Crossing_Line(float& fNextY)
{
	Point2F tCurrentP = { m_tInfo.fX , m_tInfo.fY };
	float fCurrentYSolution, fNextYSolution = WINCY;
	CLine* pCurrentLine = KJW_LINE.Get_Current_Line(tCurrentP, fCurrentYSolution);
	if (pCurrentLine)
		fNextYSolution = KJW_LINE.Get_Line_Y_Solution(pCurrentLine, tCurrentP.x + m_fXSpd);
	if ((fNextYSolution <= m_tInfo.fY + m_fYSpd)
		&& (fCurrentYSolution >= m_tInfo.fY))
	{
		fNextY = fNextYSolution;
		return true;
	}
	return false;
}
