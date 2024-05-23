#pragma once
#include "Obj.h"

class CKJW_Obj : public CObj
{
public:
	// CObj을(를) 통해 상속됨
	void Initialize() PURE;
	int Update() PURE;
	void Late_Update() PURE;
	void Render(HDC hDC) PURE;
	void Release() PURE;

	virtual void KJW_Update_Rect();
};

