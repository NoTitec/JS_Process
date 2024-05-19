#pragma once
#include "Obj.h"
class CScrewBullet : public CObj
{
public:
	CScrewBullet();
	virtual ~CScrewBullet();
public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	//������ ���ϴ� �߽������� ��ǥ
	POINT			m_tCenter;
	float			m_fRotAngle;
	float			m_fRotSpeed;

	bool			m_bStart;
};

