#pragma once
#include "Obj.h"

class CItem : public CObj
{
public:
	CItem();
	CItem(const char* _pName, int _iAttack, int _iHp, int _iMoney);
	CItem(const CItem& rhs);
	~CItem();

public:
	ITEMTYPE			Get_Type() { return m_eType; }
	void				Set_Type(ITEMTYPE eType) { m_eType = eType; }

	STATE				Get_State() { return m_eState; }
	void				Set_State(STATE eTate) { m_eState = eTate; }

public:
	virtual void Render() override;
	virtual void SelectJob()		{}
	virtual void Set_Hp(int _iHp)	{}

private:
	ITEMTYPE		m_eType;
	STATE			m_eState;
};

