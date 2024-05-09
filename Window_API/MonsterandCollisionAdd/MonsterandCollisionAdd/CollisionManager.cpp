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
