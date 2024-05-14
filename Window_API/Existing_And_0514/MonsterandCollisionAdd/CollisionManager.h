#pragma once
#include "stdafx.h"

class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static	void	Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool			Check_Sphere(CObj* _Dst, CObj* _Src);
	static void Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);

	//intersectrect 함수 안쓴 정사각형 충돌
	static void Collision_RectEx(list<CObj*>_Dst, list<CObj*> _Src);
	static bool Check_Rect(CObj* _Dst, CObj* _Src, float* pX, float* pY);
};

