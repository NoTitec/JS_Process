#pragma once
#include "Obj.h"
#include "LineMgr.h"
#include "Line.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	//������Ʈ ������ �����ϴ� �Լ�
	void Set_LinePointer(list<CLine*>* linepointer) { m_LineList = linepointer; }
	//���� Ÿ���ִ� �� �����ϴ� �Լ�
	void Set_CurLine(CLine* Line) { m_cur_line = Line; }
private:
	void		Key_Input();
	CObj*		Create_Shield();

public:
	template<typename T>
	CObj * Create_Bullet();

private:
	POINT				m_tPosin;
	//�÷��̾ ����ִ� �� ����Ʈ������
	list<CLine*>* m_LineList;
	//�� ���ͷ�����
	list<CLine*>::iterator it;
	//���� Ÿ���ִ� ��
	CLine* m_cur_line;
	bool is_Jumping;
	float t;
	float g;
	float m_fJumpStartfY;
};


// 1. ���� Ÿ�� �÷��̾� ���¸� �����Ͷ�(�� ���� ������ ������ ������ �̿�)

// �� ���� ������ ������ ������
// Y = ((y2 - y1) / (x2 - x1)) * (X - x1) + y1

// 2. �����̽� �ٸ� ������ �� ������ �����ؿͶ�

// ������ ������

// t : �ð�
// g : �߷� ���(9.8)

// Y = (V0 * sin(angle) * t) - ((1 / 2) * g * t * t);