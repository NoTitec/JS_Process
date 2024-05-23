#pragma once
#include "PHJ_Obj.h"

class CPHJ_Monster1 : public CPHJ_Obj // 플레이어 화면에서 낙하 - 지형 왔다갔다 하는 몬스터
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
	bool	m_bFall; // 낙하 여부
	bool	m_fFalltimer; // 낙하 시간
	bool	m_bMove; // 이동 방향 : false - 왼쪽, true - 오른쪽
};

