#pragma once
#include "UI.h"
class CPlayerHeadUI : public CUI
{
public:
	CPlayerHeadUI();
	virtual ~CPlayerHeadUI();

public:


	// CUI을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

};

