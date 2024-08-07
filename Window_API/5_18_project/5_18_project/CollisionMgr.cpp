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

void CCollisionMgr::Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src)
{
	float	fX(0.f), fY(0.f);

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Rect(Dst, Src, &fX, &fY))
			{
				if (fX > fY)	// 상하 충돌
				{
					if (Dst->Get_Info().fY < Src->Get_Info().fY)	// 상 충돌
					{
						Dst->Set_Y(-fY);
					}
					else // 하 충돌
					{
						Dst->Set_Y(fY);
					}

				}
				else			// 좌우 충돌
				{
					if (Dst->Get_Info().fX < Src->Get_Info().fX)	// 좌 충돌
					{
						Dst->Set_X(-fX);
					}
					else // 우 충돌
					{
						Dst->Set_X(fX);
					}
				}
			}
		}
	}
}

bool CCollisionMgr::Check_Rect(CObj* _Dst, CObj* _Src, float* pX, float* pY)
{
	float	fWidth = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float	fHeight = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float	fRadiusX = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;
	float	fRadiusY = (_Dst->Get_Info().fCY + _Src->Get_Info().fCY) * 0.5f;

	if ((fRadiusX > fWidth) && (fRadiusY > fHeight))
	{
		*pX = fRadiusX - fWidth;
		*pY = fRadiusY - fHeight;

		return true;
	}

	return false;
}
