#pragma once
#include "Bullet.h"

class CKHR_Bullet
	: public CBullet
{
public:
	CKHR_Bullet();
	virtual ~CKHR_Bullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	virtual void OnHit(CObj* _pObj) override;
};

