#pragma once
#include "SystemDefine.h"
#include "structDefine.h"
#include "enumDefine.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();
	//멤버변수
protected:
	RECT m_tRect;
	INFO m_tInfo;
	TCHAR* m_pFrameKey;
	FRAME m_tFrame;
	DIRECTION m_eDir;
	RENDERID	m_eRender;
	float m_fSpeed;
	float m_fAngle;
	//포신같은 자기위치서 떨어진 물체거리위한 변수
	float m_fDistance;
	bool m_bDead;

	CObj* m_pTarget;
public:
	//Setter
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_X(float _fX) { m_tInfo.fX += _fX; }
	void		Set_Y(float _fY) { m_tInfo.fY += _fY; }
	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	void		Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	//Getter
	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_Rect() { return m_tRect; }
	bool		Get_Dead() { return m_bDead; }
	bool		Get_HeadUIShow() { return m_HeadUIShow; }
	void		Set_HeadUIShow(bool show) { m_HeadUIShow = show; }
protected:
	void		Update_Rect();
	void		Move_Frame();

public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;
public:
	//충돌을 위해서 추가한 것들
	virtual void	OnHit(CObj* _pObj)PURE;
	OBJ_ID      m_eID;
	void      Set_ID(OBJ_ID _eID) { m_eID = _eID; }
	OBJ_ID      Get_ID() { return m_eID; }

	bool				m_HeadUIShow;
};

