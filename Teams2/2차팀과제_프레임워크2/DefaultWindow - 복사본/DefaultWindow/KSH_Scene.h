#pragma once
#include "Scene.h"

class CKSH_Scene : public CScene
{
public:
	CKSH_Scene() {}
	~CKSH_Scene() {}

	// CScene��(��) ���� ��ӵ�
	void Initialize() override;
	void Start() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

