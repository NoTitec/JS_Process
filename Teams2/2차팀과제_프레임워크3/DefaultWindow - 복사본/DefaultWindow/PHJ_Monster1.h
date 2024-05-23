#pragma once
#include "PHJ_Obj.h"

class CPHJ_Monster1 : public CPHJ_Obj // �÷��̾� ȭ�鿡�� ���� - ���� �Դٰ��� �ϴ� ����
{

public:
	CPHJ_Monster1();
	virtual ~CPHJ_Monster1();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

private:
	bool	m_bFall; // ���� ����
	bool	m_fFalltimer; // ���� �ð�
	bool	m_bMove; // �̵� ���� : false - ����, true - ������
};

