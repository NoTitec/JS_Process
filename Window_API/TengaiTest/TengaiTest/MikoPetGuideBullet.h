#pragma once
#include "Obj.h"
class CMikoPetGuideBullet : public CObj
{
public:
	CMikoPetGuideBullet();
	virtual ~CMikoPetGuideBullet();

public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

private:
};

