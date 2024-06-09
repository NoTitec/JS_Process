#pragma once
#include "Scene.h"
class CStage2 : public CScene
{
public:
	CStage2();
	virtual ~CStage2();

public:


	// CScene��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void Set_StageClearTime() { m_StageClearTime = GetTickCount(); }
private:
	int m_iScrollXSpeed;
	int m_iScrollX;
	DWORD m_dwStageEndDelay = 4000;
	DWORD m_StageClearTime;
};

