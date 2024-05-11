#pragma once

#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

public:
	void Update_Dir() override;

public:
	// get
	
	// set
private:
	// ¸â¹ö º¯¼ö
};

