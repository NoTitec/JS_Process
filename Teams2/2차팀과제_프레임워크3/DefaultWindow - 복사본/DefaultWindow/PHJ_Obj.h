#pragma once
#include "Obj.h"
class CPHJ_Obj : public CObj
{
protected: // 따로 필요해서 만든 변수들 - 열거체 떄문에 먼저 선언함
	enum WEAPON_TYPE // 플레이어 무기 타입
	{
		DEFAULT,
		TRI_BULLET,
		DEFAULT_EX,
		TRI_BULLET_EX,
		WT_END
	};
	enum OWNER // 공격물의 소유주
	{
		PLAYER,
		ENEMY,
		OWNER_END
	};
	enum PATTERN // 보스 패턴 타입
	{
		FIRE,
		DOUBLE_BULLET,
		SUMMON,
		PT_END
	};
	enum PHJ_ID
	{
		PHJ_PLAYER,
		PHJ_BULLET,
		PHJ_MONSTER,
		PHJ_BOSS,
		PHJ_END
	};
	PATTERN m_ePT;
	PHJ_ID	m_eID;
	WEAPON_TYPE m_eWtype;
	OWNER m_eOwn; // 플레이어 소속인지 적 소속인지 체크
	int m_iHp;
	int m_iAtk;

public:

	CPHJ_Obj();
	virtual ~CPHJ_Obj();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

	void	Set_WType(WEAPON_TYPE _WT) { m_eWtype = _WT; }
	PHJ_ID		Get_ID() { return m_eID; }
};

