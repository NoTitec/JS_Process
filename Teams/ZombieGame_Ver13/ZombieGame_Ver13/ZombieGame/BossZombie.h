#pragma once
#include "Obj.h"
class CBossZombie : public CObj
{
public:
	CBossZombie();
	virtual ~CBossZombie();
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

	// Player ��ǥ�� �� �����Ӹ��� ������Ʈ ��(MainGameScene Ŭ������ lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	//m_PatternType���ڷ� �޾Ƽ� �ش� Ÿ�� ���� ����
	void Pattern_Attack(int _patterntype);
	//ȣ��ɶ����� ���� ���� �������� �̵����� ����
	void Random_Dir_Degree();
	void Pos_Hp_Bar_Update();
private:
	// �÷��̾���ǥ
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	//�÷��̾���� �Ÿ�
	float   m_fdistance;
	//���� ������������
	DWORD m_dwPatternTime;
	//���� Ÿ�Կ� ���� (�ִ� 3, 0~3 4������)
	int m_iPatternType;
	//�����̵� �ð���������
	DWORD m_dwMoveTime;

	bool	m_bStuck;

	int	m_iFullHp;
	INFO m_tHpBarInfo;
	RECT m_tHpBarRect;
};

