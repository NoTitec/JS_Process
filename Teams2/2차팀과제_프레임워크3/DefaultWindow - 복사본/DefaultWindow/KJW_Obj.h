#pragma once
#include "Obj.h"

class CKJW_Obj : public CObj
{
public:
	// CObj을(를) 통해 상속됨
	void Initialize() PURE;
	int Update() PURE;
	virtual void KJW_Update_Rect();
	virtual void Update_Position()PURE;
	void Late_Update() PURE;
	void Move_Frame();
	virtual void OnMotionEnd();
	virtual void Change_Motion();
	void Render(HDC hDC) PURE;
	void Release() PURE;

	bool Check_Front_Wall();
	bool Check_Front_Floor(float& _fYSol);
	bool Check_Crossing_Line(float& fNextY);
protected:
	bool m_bJump;
	float m_fJumpPower;
	float m_fJumpTime;
	float m_fXSpd;
	float m_fYSpd;
	float m_fFootHeight;

	HDC m_hMemDC;
	int m_iCellSize ;
	int m_iCharacterSize ;

	KJW_FRAME m_tFrame;


	int m_ePreState;
	int	m_eCurState;
};

