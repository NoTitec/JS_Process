#pragma once

#include "Student.h"

class CMainApp
{
public:
	CMainApp();
	~CMainApp();

public:
	void	Initialize();
	void	Update();
	void	Release();

private:
	void	Add_Data();
	void	Print_Data();
	void	Search_Data();
	void	Delete_Data();

private:
	vector<CStudent*>		m_vecStu;
};

