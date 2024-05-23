#pragma once
#include "Obj.h"
class CKSHPlayer : public CObj
{
public:
	CKSHPlayer();
	virtual ~CKSHPlayer();
	// CObj을(를) 통해 상속됨
public:
	void OnHit(CObj* _pObj) override;
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Key_Input();
	void		Jump();
	void		Offset();
private:
	template<typename T>
	CObj* Create_Bullet();
	//포신 끝 위치
	POINT m_tBarrel;
	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;
	bool				m_isFalling;
};

