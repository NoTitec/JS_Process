#pragma once
#include "Scene.h"
class CKHR_Scene: public CScene

{
	// CScene��(��) ���� ��ӵ�
	void Initialize() override;
	void Start() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

};

