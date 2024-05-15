#include "CollisionManager.h"
#include "Obj.h"
#include "Bullet.h"
#include "Monster.h"
#include "stdafx.h"
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
	float	fWidth = _Dst->Get_Info().fX - _Src->Get_Info().fX;
	float	fHeight = _Dst->Get_Info().fY - _Src->Get_Info().fY;

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	return fRadius >= fDiagonal;
}

void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			RECT temp;
			RECT* pbullet = dynamic_cast<CBullet*>(Dst)->Get_Rect_Pointer();
			RECT* pmonster = dynamic_cast<CMonster*>(Src)->Get_Rect_Pointer();

			if (IntersectRect(&temp,pbullet,pmonster))
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
	//현재 두 사각형의 가로거리(사각형 가로 음수불가하므로 절대값)
	float fWidth = abs(_Dst->Get_Info().fX-_Src->Get_Info().fX);
	//현재 두 사각형의 세로거리(사각형 세로 음수불가하므로 절대값)
	float fHeight = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);
	//가로 반지름
	float	fRadiusX = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;
	//세로 반지름
	float	fRadiusY = (_Dst->Get_Info().fCY + _Src->Get_Info().fCY) * 0.5f;

	//두 사각형의 가로,세로 반지름 합이 각각 현재 거리보다 크다면 충둘한것
	if ((fRadiusX > fWidth) && (fRadiusY > fHeight))
	{
		*pX = fRadiusX - fWidth;
		*pY = fRadiusY - fHeight;

		return true;
	}
	return false;
}
