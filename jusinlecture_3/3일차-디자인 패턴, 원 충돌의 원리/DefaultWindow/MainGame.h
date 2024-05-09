#pragma once

#include "Player.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
#pragma region 복습
	//CObj*		m_pPlayer;
	//list<CObj*>	m_BulletList;
#pragma endregion 복습
	
	list<CObj*>		m_ObjList[OBJ_END];


	HDC			m_DC;
	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};

// 디자인 패턴
// : 코드의 구조들을 일정한 형태로 만들어 재사용하기 편리하게 만든 일정한 패턴

// https://refactoring.guru/ko/design-patterns

// 추상 팩토리 패턴 : 생성 패턴읜 한 방법으로 인스턴스를 만드는 절차를 추상화 시킴, 객체 생성 시 동반되는 공통적인 작업을 추상화 함
// 반복자 패턴 : 내부 표현 방식은 공개하지 않고 순차적인 접근 방법을 제공하는 패턴


// 1. 좌우로 움직이는 몬스터를 구현하라
// 2. 렉트 충돌을 이용하여 몬스터와 총알을 삭제하라

// bool IntersectRect(결과가 저장될 렉트의 주소, 충돌할 렉트의 주소1, 충돌할 렉트의 주소2)

// 주말 중 과제
// 1. 삼각 함수 공부
// 2. 플레이어에 중점을 기준으로 선을 하나 그림, 선을 회전 시킴(포신)
// 3. 포신이 바라보는 방향으로 플레이어 이동해야 한다