#pragma once
#include "Obj.h"
class CMikoBomb : public CObj
{
public:
	CMikoBomb();
	virtual ~CMikoBomb();

public:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

};

