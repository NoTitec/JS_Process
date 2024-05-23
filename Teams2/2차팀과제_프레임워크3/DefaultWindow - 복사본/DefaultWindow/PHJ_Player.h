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

	void			Update_Rect(); // obj Update_Rect랑 별개
	void			Offset(); // 스크롤 조정

private:
	void	Key_Input(); // 키 입력받고 행동
	void	Lining(); // 점프, 낙하 등 선타기 관리

	bool	m_bJump; // 점프 여부
	float	m_fJumptimer; // 포물선 운동용 타이머
	bool	m_bFall; // 낙하 여부
	float	m_fFalltimer; // 낙하 운동용 타이머
	float	m_fExguage; // 필살기 게이지
};

