#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;
public:
	//중점 위치 설정
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	//오브젝트 나아가는 방향 설정
	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_X(float _fX) { m_tInfo.fX += _fX; }
	void		Set_Y(float _fY) { m_tInfo.fY += _fY; }
	//자기 중점, 크기 정보구조체 반환
	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_Rect() { return m_tRect; }
	bool		Get_Dead() { return m_bDead; }
protected:
	void		Update_Rect();

protected:
	//사각형 window헤더 정의자료형$
	RECT		m_tRect;
	//Define 사용자 정의 자료형$
	INFO		m_tInfo;
	DIRECTION	m_eDir;
	float		m_fSpeed;
	float		m_fAngle;
	CObj*		m_pTarget;
	bool		m_bDead;
	//포신 길이나 총알의 회전 위한 길이 등등
	float		m_fDistance;
};

