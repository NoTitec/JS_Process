#pragma once
#include "Define.h"
class CLine
{
public:
	CLine();
	CLine(LINEPOINT& tLeft, LINEPOINT& tRight);
	~CLine();

public:
	void		Render(HDC hDC);

public:
	LINE		Get_Info() { return m_LineInfo; }
private:
	LINE		m_LineInfo;
};

