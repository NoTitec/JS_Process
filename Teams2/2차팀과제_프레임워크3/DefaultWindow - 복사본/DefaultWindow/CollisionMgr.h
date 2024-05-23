#pragma once

#include "Obj.h"
#include "Singleton.h"

class CCollisionMgr : public CSingleton<CCollisionMgr>
{
	friend CSingleton<CCollisionMgr>;
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static	void	Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool		Check_Sphere(CObj* _Dst, CObj* _Src);

	static	void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	
	static	void	Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src);
	static bool		Check_Rect(CObj* _Dst, CObj* _Src, float* pX ,float* pY);

};

#define COLLISON CCollisionMgr::Get_Instance()
