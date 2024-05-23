#pragma once
#include "Obj.h"
class CKSH_MonsterBullet :
    public CObj
{
public:
	CKSH_MonsterBullet();
	virtual ~CKSH_MonsterBullet();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;


	// CObj을(를) 통해 상속됨
	void OnHit(CObj* _pObj) override;
};

