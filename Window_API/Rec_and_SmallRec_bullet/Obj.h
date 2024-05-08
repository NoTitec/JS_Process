#pragma once

#include "Define.h"
#include <cmath>
/*
��� ������Ʈ�� �ֻ��� �θ�Ŭ���� 
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
	//�߽���ǥ�� ũ�������� �׸� RECT���� ������ ����
	void		Update_Rect();

protected:
	RECT		m_tRect;
	INFO		m_tInfo;

	float		m_fSpeed;
};