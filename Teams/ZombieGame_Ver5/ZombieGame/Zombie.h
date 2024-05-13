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
	// CObj��(��) ���� ��ӵ�
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

	// Player ��ǥ�� �� �����Ӹ��� ������Ʈ ��(MainGameScene Ŭ������ lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	void Move_Zombie();
private:
	// ��� ����
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	float   m_fdistance;

	bool	m_bStuck;
};

