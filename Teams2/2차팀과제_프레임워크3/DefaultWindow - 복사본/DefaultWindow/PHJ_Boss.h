#pragma once
#include "PHJ_Obj.h"

class CPHJ_Boss : public CPHJ_Obj
{
public:
	CPHJ_Boss();
	virtual ~CPHJ_Boss();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

private:
	bool	m_bPower; // �۵� Ʈ����
	int		m_ePattern; // ���� üũ��
	float	m_fStartY[3]; // ȭ��, �Ѿ� ���� ��ġ
	int		m_iFirstBullet; // ù �Ѿ� ��ġ
	int		m_iSecondBullet; // �ι��� �Ѿ� ��ġ
	DWORD	m_dPatternTimer; // ���� ���� ���ݿ�
};

