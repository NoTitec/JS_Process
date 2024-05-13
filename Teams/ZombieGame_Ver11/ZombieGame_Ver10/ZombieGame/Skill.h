#pragma once
#include "UI.h"
class CSkill : public CUI
{
public:
	CSkill();

	virtual ~CSkill();
public:
	// CUI을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render() override;

	void Release() override;

};

