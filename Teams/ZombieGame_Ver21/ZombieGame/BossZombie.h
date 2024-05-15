#pragma once
#pragma once
#include "Obj.h"

class CBossHpBar;
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
	int Get_Full_Hp() { return m_iFullHp; }
	// set
	void Set_Target_Pos(Vec2 _vTargetPos) { m_vTargetPos; }
	void Set_Stuck(bool _bStuck) { m_bStuck = _bStuck; }

	// Player ��ǥ�� �� �����Ӹ��� ������Ʈ ��(MainGameScene Ŭ������ lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	//���ϰ����Լ��Ѱ�
	void Pattern();
	//���ϵ�
	BOSSPATTERN Pattern1();
	//ȣ��ɶ����� ���� ���� �������� �̵����� ����
	void Random_Dir_Degree();
	void Set_BossBulletList(list<CObj*>* _pBulletList) { m_pBossBulletList = _pBulletList; }

	void Pos_Hp_Bar_Update();
private:
	// �÷��̾���ǥ
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	//�÷��̾���� �Ÿ�
	float   m_fdistance;
	//���� ������������
	DWORD m_CollisionTime;
	//���� enum ����
	BOSSPATTERN m_ePattern;
	//���� �ð� ���� ���� ����
	ULONGLONG m_fSaveTime;
	//���� ���� �ð�(ms ����)
	ULONGLONG m_fPatternCoolTime;
	//�����̵� �ð���������
	DWORD m_dwMoveTime;
	//���� �Ѿ� ���� ����Ʈ
	list<CObj*>* m_pBossBulletList;
	bool	m_bStuck;
	int	m_iFullHp;
	INFO m_tHpBarInfo;
	RECT m_tHpBarRect;

	CBossHpBar* m_pBossHpBar;
};

