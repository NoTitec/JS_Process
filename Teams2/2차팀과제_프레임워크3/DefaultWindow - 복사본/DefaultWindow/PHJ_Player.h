#pragma once
#include "PHJ_Obj.h"

class CPHJ_Player : public CPHJ_Obj
{
public:

	CPHJ_Player();
	virtual ~CPHJ_Player();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

	void			Update_Rect(); // obj Update_Rect�� ����
	void			Offset(); // ��ũ�� ����

private:
	void	Key_Input(); // Ű �Է¹ް� �ൿ
	void	Lining(); // ����, ���� �� ��Ÿ�� ����

	bool	m_bJump; // ���� ����
	float	m_fJumptimer; // ������ ��� Ÿ�̸�
	bool	m_bFall; // ���� ����
	float	m_fFalltimer; // ���� ��� Ÿ�̸�
	float	m_fExguage; // �ʻ�� ������
};

