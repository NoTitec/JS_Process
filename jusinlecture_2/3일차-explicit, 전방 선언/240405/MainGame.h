#pragma once

#include "Student.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();		// 멤버 변수의 값을 설정하는 함수(초기화)
	void	Update();			// 매 프레임마다 데이터를 갱신하는 함수
	void	Release();			// 동적 할당한 메모리를 해제하는 코드를 모아놓은 함수

private:
	CStudent*		m_pStudent;

};

