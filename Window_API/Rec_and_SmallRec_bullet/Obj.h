#pragma once

#include "Define.h"
#include <cmath>
/*
모든 오브젝트의 최상위 부모클래스 
*/
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void Set_Speed()
	{
		m_fSpeed =sqrt(m_fSpeed);
	}
public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;

protected:
	//중심좌표와 크기정보로 그릴 RECT정보 데이터 설정
	void		Update_Rect();

protected:
	RECT		m_tRect;
	INFO		m_tInfo;

	float		m_fSpeed;
};