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
	virtual void OnHit(CObj* _pObj) override;

	POINT Get_PetPoint() { return m_tPetPoint; }
	int Get_Power() { return m_iPower; }
private:
	void		Key_Input();
	void		Offset();
	void		Motion_Change();
	void		Create_Basic_Bullet();
	void		Create_Bomb();
public:
	template<typename T>
	CObj* Create_Bullet();

private:
	POINT				m_tPetPoint;

	int					m_iPower;

	float				m_fTime;
	DWORD				m_dwBulletGenarateSpeed;
	DWORD				m_dwBulletGenarateTime;
	DWORD				m_dwBombGenarateDelay;
	DWORD				m_dwBombGenarateTime;
	POINT				m_tBombGenaratePoint;
	bool				m_bBombKeyOn;
	DWORD				m_dwDebugMassageTime;
	STATE				m_ePreState;
	STATE				m_eCurState;
};

template<typename T>
inline CObj* CPlayer::Create_Bullet()
{
	return nullptr;
}
