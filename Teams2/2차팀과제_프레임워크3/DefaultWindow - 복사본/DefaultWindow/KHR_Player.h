#pragma once
#include "Obj.h"

class CKHR_Player
	: public CObj
{
	enum PLAYER_SCENE
	{
		PLAYER_START,
		PLAYER_LIVE,
		PLAYER_EXIT,
		PLAYER_END
	};

	enum PLAYER_STATE
	{
		IDLE,
		WALK,
		JUMP,
		ATTACK,
		STATE_END
	};

public:
	CKHR_Player();
	virtual ~CKHR_Player();

public:
	virtual void	Initialize()		override;
	virtual int		Update()			override;
	virtual void	Late_Update()		override;
	virtual void	Render(HDC hDC)		override;
	virtual void	Release()			override;
	virtual void	OnHit(CObj* _pObj)	override;
	virtual void	Move_Frame()		override;

public:
	void			Key_Input();
	void			Jump();
	void			Offset();
	void			Change_Motion();

	void			Set_FrameInfo(int _iFrameStart, int _iFrameEnd, int _iMotion, DWORD _dwTime, DWORD _dwSpeed)
	{
		m_tFrame.iFrameStart	= _iFrameStart;
		m_tFrame.iFrameEnd		= _iFrameEnd;
		m_tFrame.iMotion		= _iMotion;
		m_tFrame.dwTime			= _dwTime;
		m_tFrame.dwSpeed		= _dwSpeed;
	}

private:
	float			m_fPower;
	float			m_fTime;
	bool			m_bIsJump;

	PLAYER_SCENE	m_ePlayerScene;

	PLAYER_STATE	m_ePreState;
	PLAYER_STATE	m_eCurState;
};

