#pragma once
#include "Obj.h"
class CFollowBullet : public CObj
{
public:
	CFollowBullet();
	virtual ~CFollowBullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
};

