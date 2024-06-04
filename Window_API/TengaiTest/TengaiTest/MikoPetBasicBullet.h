#pragma once
#include "Obj.h"
class CMikoPetBasicBullet : public CObj
{
public:
	CMikoPetBasicBullet();
	virtual ~CMikoPetBasicBullet();

public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

