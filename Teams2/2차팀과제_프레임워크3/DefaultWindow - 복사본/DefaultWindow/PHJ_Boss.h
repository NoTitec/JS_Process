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
	bool	m_bPower; // 작동 트리거
	int		m_ePattern; // 패턴 체크용
	float	m_fStartY[3]; // 화염, 총알 시작 위치
	int		m_iFirstBullet; // 첫 총알 위치
	int		m_iSecondBullet; // 두번쨰 총알 위치
	DWORD	m_dPatternTimer; // 패턴 사이 간격용
};

