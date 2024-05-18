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

	//선리스트 포인터 세팅하는 함수
	void Set_LinePointer(list<CLine*>* linepointer) { m_LineList = linepointer; }
	//지금 타고있는 선 세팅하는 함수
	void Set_CurLine(CLine* Line) { m_cur_line = Line; }
private:
	void		Key_Input();
	CObj*		Create_Shield();

public:
	template<typename T>
	CObj * Create_Bullet();

private:
	POINT				m_tPosin;
	//플레이어가 들고있는 선 리스트포인터
	list<CLine*>* m_LineList;
	//선 이터레이터
	list<CLine*>::iterator it;
	//지금 타고있는 선
	CLine* m_cur_line;
	bool is_Jumping;
	float t;
	float g;
	float m_fJumpStartfY;
};


// 1. 선을 타는 플레이어 상태를 만들어와라(두 점을 지나는 직선의 방정식 이용)

// 두 점을 지나는 직선의 방정식
// Y = ((y2 - y1) / (x2 - x1)) * (X - x1) + y1

// 2. 스페이스 바를 눌렀을 때 점프를 구현해와라

// 포물선 방정식

// t : 시간
// g : 중력 계수(9.8)

// Y = (V0 * sin(angle) * t) - ((1 / 2) * g * t * t);