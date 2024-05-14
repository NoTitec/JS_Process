#pragma once

#include "Scene.h"
class CBossGameScene : public CScene
{
public:
	CBossGameScene();
	virtual ~CBossGameScene();
public:
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

};

