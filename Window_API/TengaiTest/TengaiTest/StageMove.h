#pragma once
#include "Scene.h"
class CStageMove : public CScene
{
public:
	CStageMove();
	virtual ~CStageMove();
public:
	// CScene을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
private:
	DWORD m_dwNextSceneDelayTime;
};

