#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	enum STATE { IDLE, WALK, ATTACK, HIT, DEAD, ST_END };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void		Key_Input();
	CObj*		Create_Shield();
	void		Jump();
	void		Offset();
	void		Motion_Change();

public:
	template<typename T>
	CObj * Create_Bullet();

private:
	POINT				m_tPosin;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	STATE				m_ePreState;
	STATE				m_eCurState;

};


// 1. ���� Ÿ�� �÷��̾� ���¸� �����Ͷ�(�� ���� ������ ������ ������ �̿�)

// �� ���� ������ ������ ������
// Y = ((y2 - y1) / (x2 - x1)) * (X - x1) + y1

// 2. �����̽� �ٸ� ������ �� ������ �����ؿͶ�

// ������ ������

// t : �ð�
// g : �߷� ���(9.8)

// Y = (V0 * sin(angle) * t) - ((1 / 2) * g * t * t);