#pragma once
#include "Obj.h"

class CBarrier : public CObj
{
public:
	CBarrier();
	~CBarrier();
public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
public:
	void PlayerPos_Update(Vec2 _vPlayerPos);
public:
	void BarrierType1();
public:
	// get

	// set
private:
	// ��� ����
	Vec2 m_vPlayerPos;
};

