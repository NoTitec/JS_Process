#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir;  }
	void		Set_Dead() { m_bDead = true; }

	INFO		Get_Info() { return m_tInfo; }

public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;

protected:
	void		Update_Rect();

protected:
	RECT		m_tRect;
	INFO		m_tInfo;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	bool		m_bDead;
	float		m_fAngle;

	float		m_fDistance;

};

