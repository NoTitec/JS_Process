#pragma once
#include "Scene.h"
class CLogo : public CScene
{
public:
	CLogo();
	virtual ~CLogo();

public:
	// CScene��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
private:
	HWND m_hVideo;
};

