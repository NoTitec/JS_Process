#pragma once
#include "Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();
public:
	static void Collide_Portal(
		list<CObj*> _itemList,
		list<CObj*> _playerList
	);

	static void Collide_Turret(
		list<CObj*> _turretList,
		list<CObj*> _playerList,
		list<CObj*>* _zombieList,
		list<CObj*>* _bulletList
	);

	static void Collide_Boss_With_Player(list<CObj*> _bossList, list<CObj*> _playerList);
	static void Collide_Bullet_With_Zombie(list<CObj*>_bulletList, list<CObj*>_zombieList);

	static void Collide_Item(list<CObj*> _Dst, list<CObj*> _Src);
	static void Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool Check_Sphere(CObj* _Dst, CObj* _Src);
};

