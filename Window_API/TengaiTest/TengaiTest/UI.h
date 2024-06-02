#pragma once
#include "SystemDefine.h"
#include "structDefine.h"
#include "enumDefine.h"
#include "Obj.h"
class CUI
{
public:
	CUI();
	virtual ~CUI();

protected:
	CObj* m_pOwnerObject;
	RECT m_tRect;
	INFO m_tInfo;
	TCHAR* m_pFrameKey;
	FRAME m_tFrame;
	RENDERID	m_eRender;
	bool m_bShow;
	int m_iDrawID;
public:
	void Set_Owner(CObj* obj)
	{
		m_pOwnerObject = obj;
	}
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_X(float _fX) { m_tInfo.fX += _fX; }
	void		Set_Y(float _fY) { m_tInfo.fY += _fY; }
	void		Set_Show(bool show) { m_bShow = show; }
	void		Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

protected:
	void		Update_Rect();
	void		Move_Frame();
	void		Move_Frame_one_cycle();
public:
	virtual void	Initialize()PURE;
	virtual int		Update()PURE;
	virtual void	Late_Update()PURE;
	virtual void	Render(HDC hDC)PURE;
	virtual void	Release()PURE;
};

