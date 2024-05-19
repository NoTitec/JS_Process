#pragma once
#include "stdafx.h"
#include "Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool Check_Sphere(CObj* _Dst, CObj* _Src);
	//intersectRect 함수 이용함 사각형 충돌판정
	static	void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	//intersectRect 함수 없이 사각형 충돌판정
	static	void	Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src);
	static bool		Check_Rect(CObj* _Dst, CObj* _Src, float* pX, float* pY);
};

