#pragma once
#include "Player.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
enum SCENE_TYPE
{
	HGH_SCENE,
	KRH_SCENE,
	KJW_SCENE,
	KSH_SCENE,
	PHJ_SCENE,
	END
};

class CItem;
class CMonster;
class CSpawner;
class CScene
{
public:
	CScene();
	virtual ~CScene();

	virtual void	Initialize() PURE;
	virtual void	Start() PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;


protected:

};



