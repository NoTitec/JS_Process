#pragma once
#include "Obj.h"
class CBombItem : public CObj
{
public:
	CBombItem();
	virtual ~CBombItem();
public:



	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

