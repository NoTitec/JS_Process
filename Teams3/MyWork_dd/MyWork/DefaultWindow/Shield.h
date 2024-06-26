#pragma once
#include "Obj.h"

class CShield : public CObj
{

public:;
	CShield();
	virtual ~CShield() override;

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	void Set_Local_Pos(D3DXVECTOR3 vPos);

private:
	
};

