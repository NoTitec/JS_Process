#pragma once
#include "Obj.h"
#include "EventDefine.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
class CMonsterBullet1 : public CObj
{
public:
	CMonsterBullet1();
	virtual ~CMonsterBullet1();
public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

