#pragma once
#include "UI.h"
class CPlayerHeadUI : public CUI
{
public:
	CPlayerHeadUI();
	virtual ~CPlayerHeadUI();

public:


	// CUI��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

};

