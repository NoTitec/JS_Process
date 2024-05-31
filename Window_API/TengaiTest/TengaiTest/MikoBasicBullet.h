#pragma once
#include "Obj.h"
class CMikoBasicBullet : public CObj
{
public:
	CMikoBasicBullet();
	virtual ~CMikoBasicBullet();
public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	int iFrameindex;
};

