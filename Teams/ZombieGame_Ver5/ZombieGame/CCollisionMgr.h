#pragma once
#include "Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();
public:
	static void Collide_Turret(
		list<CObj*> _turretList,
		list<CObj*> _playerList,
		list<CObj*>* _zombieList,
		list<CObj*>* _bulletList
	);

	static void Collide_Item(list<CObj*> _Dst, list<CObj*> _Src);
	static void Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool Check_Sphere(CObj* _Dst, CObj* _Src);
};

