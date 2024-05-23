#pragma once
#include "Scene.h"

class CKJW_Scene : public CScene
{
public:
	CKJW_Scene();
	~CKJW_Scene();

	// CScene을(를) 통해 상속됨
	void Initialize() override;
	void Start() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
private:
	HDC m_hGroundDC;
	CObj* m_pBoss;
	CObj* m_pPlayer;
};

