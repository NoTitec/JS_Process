#pragma once
#include "Obj.h"
class CPowerItem : public CObj
{
public:
	CPowerItem();
	virtual ~CPowerItem();

public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;
	virtual void OnHit(CObj* _pObj) override;
};

