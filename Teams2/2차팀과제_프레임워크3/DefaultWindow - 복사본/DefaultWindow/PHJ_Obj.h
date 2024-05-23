#pragma once
#include "Obj.h"
class CPHJ_Obj : public CObj
{
protected: // ���� �ʿ��ؼ� ���� ������ - ����ü ������ ���� ������
	enum WEAPON_TYPE // �÷��̾� ���� Ÿ��
	{
		DEFAULT,
		TRI_BULLET,
		DEFAULT_EX,
		TRI_BULLET_EX,
		WT_END
	};
	enum OWNER // ���ݹ��� ������
	{
		PLAYER,
		ENEMY,
		OWNER_END
	};
	enum PATTERN // ���� ���� Ÿ��
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
	OWNER m_eOwn; // �÷��̾� �Ҽ����� �� �Ҽ����� üũ
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

