#pragma once
#include "UI.h"
class CStartButton : public CUI
{
public:
	CStartButton();
	virtual ~CStartButton();

public:


	// CUI��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

};

