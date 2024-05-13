#pragma once
#include "Obj.h"
class CCombo : public CObj
{
public:
	CCombo();
	virtual ~CCombo();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

private:
	int m_iComboNumber;
};