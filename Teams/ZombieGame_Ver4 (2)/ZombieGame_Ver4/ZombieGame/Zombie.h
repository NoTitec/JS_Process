#pragma once
#include "Obj.h"
#include "Enum.h"

class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();

public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

public:
	//방향조절
	void Dir_Update() override;

public:
	//dir방향으로 이동
	void Move_Zombie();
public:
	// get

	// set

	// Player 좌표를 매 프레임마다 업데이트 중(MainGameScene 클래스의 lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }
private:
	// 멤버 변수
	Vec2	m_vTargetPos;
	bool	m_bStuck;
	ZOMBIE_TYPE m_eZtype;
	float m_fdistance;
};

