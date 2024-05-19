#pragma once
#include "Obj.h"
class CScrewBullet : public CObj
{
public:
	CScrewBullet();
	virtual ~CScrewBullet();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	//렌더링 안하는 중심축위한 좌표
	POINT			m_tCenter;
	float			m_fRotAngle;
	float			m_fRotSpeed;

	bool			m_bStart;
};

