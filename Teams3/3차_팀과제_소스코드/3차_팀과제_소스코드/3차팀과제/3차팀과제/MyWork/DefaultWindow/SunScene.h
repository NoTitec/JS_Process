#pragma once

#include "Scene.h"

class CSunScene : public CScene
{
public:

	CSunScene();
	virtual ~CSunScene();

public:


	// CScene��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

};

