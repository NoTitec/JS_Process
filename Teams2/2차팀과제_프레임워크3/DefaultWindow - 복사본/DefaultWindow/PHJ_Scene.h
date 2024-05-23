#pragma once

#include "Scene.h"
#include "PHJ_Player.h"
#include "PHJ_Boss.h"
#include "PHJ_Monster1.h"
#include "PHJ_Monster2.h"

class CPHJ_Scene : public CScene
{
public:
	CPHJ_Scene();
	virtual ~CPHJ_Scene();

	virtual void	Initialize() override;
	virtual void	Start() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
private:
	bool	m_bClear; // Ŭ���� Ȯ�ο� ����
	bool	m_bSpawner; // ���� ��ȯ
	DWORD	m_dSpawntimer1; // ����1 ������ Ÿ�̸�
	DWORD	m_dSpawntimer2; // ����1 ������ Ÿ�̸�
};

