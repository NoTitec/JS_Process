#pragma once

#include "Scene.h"
class CMainMenuScene : public CScene
{
public:
	// CScene��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

private:

};

