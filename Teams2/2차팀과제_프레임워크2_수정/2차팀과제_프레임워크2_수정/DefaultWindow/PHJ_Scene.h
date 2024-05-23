#pragma once
#include "Scene.h"
class CPHJ_Scene : public CScene
{
	// CScene을(를) 통해 상속됨
	void Initialize() override;
	void Start() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

