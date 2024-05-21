#pragma once
#include "Scene.h"
class CScene1 : public CScene
{
public:

	CScene1() {}
	~CScene1();

	int	 Update() override;

	//SCENE_STATE CheckCurrentState() override;

	// CScene을(를) 통해 상속됨
	void Initialize() override;

	void Start() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;
private:
};

