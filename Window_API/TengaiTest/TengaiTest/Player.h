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
	void Set_State_ForwardMove() {
		m_eCurState = FORWARDMOVE; m_pFrameKey = L"Miko_Fly_Forward";
	}
	POINT Get_PetPoint() { return m_tPetPoint; }
	int Get_Power() { return m_iPower; }
	int Get_BombCount() { return m_iBombCount; }
private:
	void		Key_Input();
	void		Offset();
	void		Motion_Change();
	void		Create_Basic_Bullet();
	void		Create_Bomb();
	void		Bullet_Sound_Control();
public:
	template<typename T>
	CObj* Create_Bullet();

private:
	POINT				m_tPetPoint;

	int					m_iPower;
	int					m_iBombCount;
	float				m_fTime;
	DWORD				m_dwBulletGenarateSpeed;
	DWORD				m_dwBulletGenarateTime;
	DWORD				m_dwBulletSoundSpeed;
	DWORD				m_dwBulletSoundTime;
	DWORD				m_dwBulletSoundSpeed2;
	DWORD				m_dwBulletSoundTime2;
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
