#pragma once

#include "Obj.h"
class CBomb : public CObj
{
public:
	CBomb();
	virtual ~CBomb();

public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

private:
	static const float BOMB_RADIUS;
};