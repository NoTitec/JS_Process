#pragma once
#include "Define.h"
#include "Obj.h"
#include "stdafx.h"
class CMainGame
{
public:
	//맴버초기화
	CMainGame();
	//메모리 해제
	~CMainGame();

public:
	//핸들받아오고, 플레이어 생성
	void Initialize();
	//플레이어 업데이트
	void Update();
	//플레이어 랜더
	void Render();
	//맴버 해제
	void Release();
private:
	CObj* m_pPlayer;
	list<CObj*>	m_BulletList;
	HDC m_DC;
	
};