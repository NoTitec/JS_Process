#pragma once
#include "Obj.h"
class CBox : public CObj
{
public:
	CBox();
	virtual ~CBox();
public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

