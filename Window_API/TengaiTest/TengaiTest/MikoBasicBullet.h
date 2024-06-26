#pragma once
#include "Obj.h"
class CMikoBasicBullet : public CObj
{
public:
	CMikoBasicBullet();
	virtual ~CMikoBasicBullet();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	virtual void OnHit(CObj* _pObj) override;
private:
	int iFrameindex;
};

