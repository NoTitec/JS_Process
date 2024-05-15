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
	// CObj��(��) ���� ��ӵ�
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
	// Player ��ǥ�� �� �����Ӹ��� ������Ʈ ��(MainGameScene Ŭ������ lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	void Move_Zombie();
	
	// ü�¹� �߰��� ���� �߰��߽��ϴ�. �Ű� �� �ʿ� X
	void Pos_Hp_Bar_Update();
private:
	// ��� ����
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	float   m_fdistance;
	DWORD m_dwTime;
	bool	m_bStuck;
	float m_fmaxSpeed;
	// ü�¹� �߰��� ���� �߰��߽��ϴ�. �Ű� �� �ʿ� X
	int	m_iFullHp;
	INFO m_tHpBarInfo;
	RECT m_tHpBarRect;
};

