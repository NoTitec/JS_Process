#pragma once
#include "UI.h"
class CPlayerBombCount : public CUI
{
public:
	CPlayerBombCount();
	virtual ~CPlayerBombCount();

public:


	// CUI을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;
private:
	int m_iPlayerBombCount;
};

