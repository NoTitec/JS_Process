#pragma once
#include "Obj.h"
class CScrewBullet : public CObj
{
public:
	CScrewBullet();
	virtual ~CScrewBullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
private:

	//총알 회전위한 안보이는 중점
	POINT			m_tCenter;
	float			m_fRotAngle;
	float			m_fRotSpeed;

	bool			m_bStart;

};

