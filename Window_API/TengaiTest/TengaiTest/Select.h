#pragma once
#include "Scene.h"
class CSelect : public CScene
{
public:

	CSelect();
	virtual ~CSelect();

public:


	// CScene을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

private:
	int m_iselectindex;
};

