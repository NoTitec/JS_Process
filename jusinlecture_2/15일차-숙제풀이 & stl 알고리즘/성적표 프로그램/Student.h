#pragma once

#include "Define.h"

class CStudent
{
public:
	CStudent();
	~CStudent();

public:
	INFO		Get_Info() { return m_tInfo; }

public:
	void		Input_Data();
	void		Output_Data();

private:
	INFO		m_tInfo;
};

