#pragma once
#include "UI.h"
class CPlayerBombCount : public CUI
{
public:
	CPlayerBombCount();
	virtual ~CPlayerBombCount();

public:


	// CUI��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;
private:
	int m_iPlayerBombCount;
};

