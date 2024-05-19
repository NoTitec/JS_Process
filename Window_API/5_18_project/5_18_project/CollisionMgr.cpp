#include "CollisionMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj* _Dst, CObj* _Src)
{
	float FWidth = (_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float FHeight = (_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float	fDiagonal = sqrt(FWidth * FWidth + FHeight * FHeight);
	float fTwoRadius= (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	return fTwoRadius >= fDiagonal;
}

void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT	rc{};


	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &(Dst->Get_Rect()), &(Src->Get_Rect())))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}