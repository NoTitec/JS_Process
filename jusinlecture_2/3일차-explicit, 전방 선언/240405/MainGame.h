#pragma once

#include "Student.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();		// ��� ������ ���� �����ϴ� �Լ�(�ʱ�ȭ)
	void	Update();			// �� �����Ӹ��� �����͸� �����ϴ� �Լ�
	void	Release();			// ���� �Ҵ��� �޸𸮸� �����ϴ� �ڵ带 ��Ƴ��� �Լ�

private:
	CStudent*		m_pStudent;

};

