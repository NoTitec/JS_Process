#pragma once

// #include "Player.h"

// 전방 선언 : 상호 포함 또는 참조를 방지하는 기법, 자료형의 유무만 알려줌

// 1. 전방 선언 시, 객체 포인터를 멤버 변수로 선언해야 한다.
// 2. cpp 파일에 헤더를 포함시켜줘야 한다.

class CPlayer;

class CMonster
{
public:
	CMonster();
	~CMonster();

public:
	void	Draw();
	
	void	Output()
	{
		cout << "academy" << endl;
	}

private:
	CPlayer*			m_pPlayer;
};

