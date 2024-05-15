#pragma once
#include "Obj.h"

class CHpBar;
class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();
public:
	void Dir_Update() override;
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
public:
	// get
	Vec2 Get_Target_Pos() { return m_vTargetPos; }
	bool Get_Stuck() { return m_bStuck; }
	// set
	void Set_Target_Pos(Vec2 _vTargetPos) { m_vTargetPos; }
	void Set_Stuck(bool _bStuck) { m_bStuck = _bStuck; }
	void Set_Speed_Zero();
	// Player 좌표를 매 프레임마다 업데이트 중(MainGameScene 클래스의 lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	void Move_Zombie();
	
	// 체력바 추가를 위해 추가했습니다. 신경 쓸 필요 X
	void Pos_Hp_Bar_Update();
private:
	// 멤버 변수
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	float   m_fdistance;
	DWORD m_dwTime;
	bool	m_bStuck;
	float m_fmaxSpeed;
	// 체력바 추가를 위해 추가했습니다. 신경 쓸 필요 X
	int	m_iFullHp;
	INFO m_tHpBarInfo;
	RECT m_tHpBarRect;
};

