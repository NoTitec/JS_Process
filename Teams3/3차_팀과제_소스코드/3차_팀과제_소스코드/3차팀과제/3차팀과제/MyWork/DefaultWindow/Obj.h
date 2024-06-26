#pragma once

#include "Define.h"
#include "Structs.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO&		Get_Info() const { return m_tInfo; }

public:
	virtual void	Initialize()		PURE;
	virtual int		Update()			PURE;
	virtual void	Late_Update()		PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release()			PURE;

	void Set_Pos(float fX, float fY)
	{
		m_tInfo.vPos.x = fX;
		m_tInfo.vPos.y = fY;
	}
protected:
	INFO		m_tInfo;
	float		m_fSpeed;
};

