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
	bool	m_bClear; // 클리어 확인용 변수
	bool	m_bSpawner; // 몬스터 소환
	DWORD	m_dSpawntimer1; // 몬스터1 스폰용 타이머
	DWORD	m_dSpawntimer2; // 몬스터1 스폰용 타이머
};

