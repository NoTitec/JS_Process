#pragma once

#include "Scene.h"

class CNYScene : public CScene
{

public:
	CNYScene();
	~CNYScene() override;


	// Inherited via CScene
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	
};

