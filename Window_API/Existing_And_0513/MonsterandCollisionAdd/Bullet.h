#pragma once
#include "Obj.h"
#include "stdafx.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
};

