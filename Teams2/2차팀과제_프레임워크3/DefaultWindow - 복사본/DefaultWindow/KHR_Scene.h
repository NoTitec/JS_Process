#pragma once
#include "Scene.h"

class CKHR_Scene
	: public CScene
{
public:
	CKHR_Scene();
	virtual ~CKHR_Scene();

public:
	void Initialize() override;
	int	 Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

	void Start() override;
};

