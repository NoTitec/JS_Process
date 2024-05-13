#pragma once
#include "Obj.h"
#include "Enum.h"

class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();

public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

public:
	//��������
	void Dir_Update() override;

public:
	//dir�������� �̵�
	void Move_Zombie();
public:
	// get

	// set

	// Player ��ǥ�� �� �����Ӹ��� ������Ʈ ��(MainGameScene Ŭ������ lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }
private:
	// ��� ����
	Vec2	m_vTargetPos;
	bool	m_bStuck;
	ZOMBIE_TYPE m_eZtype;
	float m_fdistance;
};

