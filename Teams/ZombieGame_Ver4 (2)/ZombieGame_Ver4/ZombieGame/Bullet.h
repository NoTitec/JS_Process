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
	void BulletType1();
	void BulletType2();
	void BulletType3();

public:
	// get
	
	// set
private:
	// ��� ����
};

