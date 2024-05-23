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
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }

	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_Rect() { return m_tRect; }

	void		Set_X(float _fX) { m_tInfo.fX += _fX; }
	void		Set_Y(float _fY) { m_tInfo.fY += _fY; }

	bool		Get_Dead() { return m_bDead; }
	virtual void	OnHit(CObj* _pObj)PURE;
public:
	void      Set_ID(OBJ_ID _eID) { m_eID = _eID; }
	OBJ_ID      Get_ID() { return m_eID; }
private:
	OBJ_ID      m_eID;
public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;
	virtual void	Move_Frame();

protected:
	void			Update_Rect();
protected:
	RECT		m_tRect;
	INFO		m_tInfo;
	DIRECTION	m_eDir;
	FRAME       m_tFrame;
	TCHAR*		m_pFrameKey;
	float		m_fSpeed;
	bool		m_bDead;
	float		m_fAngle;

	float		m_fDistance;

	CObj*		m_pTarget;

};

