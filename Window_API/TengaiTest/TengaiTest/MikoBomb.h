#pragma once
#include "Obj.h"
class CMikoBomb : public CObj
{
public:
	CMikoBomb();
	virtual ~CMikoBomb();

public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

