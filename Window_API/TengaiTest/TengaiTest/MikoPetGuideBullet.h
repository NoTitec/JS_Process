#pragma once
#include "Obj.h"
class CMikoPetGuideBullet : public CObj
{
public:
	CMikoPetGuideBullet();
	virtual ~CMikoPetGuideBullet();

public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

private:
};

