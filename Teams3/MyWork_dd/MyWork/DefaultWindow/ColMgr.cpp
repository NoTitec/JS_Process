#include "stdafx.h"
#include "ColMgr.h"
#include "Obj.h"
#include "MainGame.h"

CColMgr* CColMgr::m_pInstance = nullptr;

CColMgr::CColMgr()
{

}

CColMgr::~CColMgr()
{

}


void CColMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	/*for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Dst == Src)
				continue;

			if (Check_Rect(Dst, Src))
			{
				Src->m_bCol = true;

				
			}
		}
	}*/
}

bool CColMgr::Check_Rect(CObj* _Dst, CObj* _Src)
{

	/*float fWidth = abs((_Dst->Get_Info().fX + iScrollX - 8) - (_Src->Get_Info().fX + iScrollX - 8));
	float fHeight = abs((_Dst->Get_Info().fY + iScrollY - 8) - (_Src->Get_Info().fY + iScrollY - 8));

	float fRadiusX = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f - 15;
	float fRadiusY = (_Dst->Get_Info().fCY + _Src->Get_Info().fCY) * 0.5f - 15;

	if ((fRadiusX >= fWidth) && (fRadiusY >= fHeight))
		return true;
	return false;*/

	return false;
}



