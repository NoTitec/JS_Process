#pragma once
#include "Define.h"

class CKHR_Line
{
public:
	CKHR_Line();
	CKHR_Line(LINEPOINT& tLeft, LINEPOINT& tRight);
	~CKHR_Line();

public:
	void		Render(HDC hDC);

public:
	LINE		Get_Info() { return m_tInfo; }
	float		Get_Y(float _fPlayerPosX);
	float		Get_X(float _fPlayerPosY);

private:
	LINE		m_tInfo;
};

