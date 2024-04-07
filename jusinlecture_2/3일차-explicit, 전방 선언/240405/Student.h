#pragma once

#include "Define.h"

class CStudent
{
public:
	CStudent();
	~CStudent();

public:
	void	Initialize();
	void	Release();

	void	Input_Data();
	void	Output_Data();

private:
	INFO*	m_pInfo;
	int		m_iSize;
};

