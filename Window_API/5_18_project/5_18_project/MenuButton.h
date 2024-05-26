#pragma once
#include "Obj.h"
class CMenuButton : public CObj
{
public:
	CMenuButton();
	virtual ~CMenuButton();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	int		m_iDrawID;

};

