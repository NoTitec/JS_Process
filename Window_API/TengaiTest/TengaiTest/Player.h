#pragma once
#include "Obj.h"
class CPlayer : public CObj
{
public:
	enum STATE { FORWARDMOVE, BACKMOVE, HITED, DEAD, ST_END };

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
	void		Offset();
	void		Motion_Change();
	void		Create_Basic_Bullet();
public:
	template<typename T>
	CObj* Create_Bullet();

private:
	POINT				m_tPetPoint;

	int					m_iPower;
	float				m_fTime;
	DWORD				m_dwBulletGenarateSpeed;
	DWORD				m_dwBulletGenarateTime;
	STATE				m_ePreState;
	STATE				m_eCurState;
};

template<typename T>
inline CObj* CPlayer::Create_Bullet()
{
	return nullptr;
}
