#pragma once

#include "Scene.h"
class CMainMenuScene : public CScene
{
public:
	// CScene을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

private:

};

