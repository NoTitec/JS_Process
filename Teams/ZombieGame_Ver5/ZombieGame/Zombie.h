#pragma once
#include "Obj.h"

class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();
public:
	void Dir_Update() override;
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
public:
	// get
	Vec2 Get_Target_Pos() { return m_vTargetPos; }
	bool Get_Stuck() { return m_bStuck; }
	// set
	void Set_Target_Pos(Vec2 _vTargetPos) { m_vTargetPos; }
	void Set_Stuck(bool _bStuck) { m_bStuck = _bStuck; }

	// Player 좌표를 매 프레임마다 업데이트 중(MainGameScene 클래스의 lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	void Move_Zombie();
private:
	// 멤버 변수
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	float   m_fdistance;

	bool	m_bStuck;
};

