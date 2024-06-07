#pragma once
#include "Obj.h"
class CBladeMonster : public CObj
{
public:
	CBladeMonster();
	virtual ~CBladeMonster();

public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;
private:

	int m_iHp;
	float m_fmaxAngle;
};

