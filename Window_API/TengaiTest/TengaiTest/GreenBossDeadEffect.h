#pragma once
#include "Obj.h"
class CGreenBossDeadEffect : public CObj
{
public:

	CGreenBossDeadEffect();
	virtual ~CGreenBossDeadEffect();
public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

