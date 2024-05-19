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
	//���� ��ġ ����
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	//������Ʈ ���ư��� ���� ����
	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_X(float _fX) { m_tInfo.fX += _fX; }
	void		Set_Y(float _fY) { m_tInfo.fY += _fY; }
	//�ڱ� ����, ũ�� ��������ü ��ȯ
	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_Rect() { return m_tRect; }
	bool		Get_Dead() { return m_bDead; }
protected:
	void		Update_Rect();

protected:
	//�簢�� window��� �����ڷ���$
	RECT		m_tRect;
	//Define ����� ���� �ڷ���$
	INFO		m_tInfo;
	DIRECTION	m_eDir;
	float		m_fSpeed;
	float		m_fAngle;
	CObj*		m_pTarget;
	bool		m_bDead;
	//���� ���̳� �Ѿ��� ȸ�� ���� ���� ���
	float		m_fDistance;
};

