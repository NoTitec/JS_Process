#pragma once
#include "PHJ_Obj.h"

class CPHJ_Monster2 : public CPHJ_Obj // �ҽ�ó�� �Ʒ����� Ƣ��Դ� �ٽ� ���� ��ġ�����
{

public:
	CPHJ_Monster2();
	virtual ~CPHJ_Monster2();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

private:
	float	m_fJumptimer;
};

