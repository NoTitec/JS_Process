#pragma once

#include "Obj.h"

class CPlayer final : public CObj
{
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF, END };

public:
	CPlayer();
	~CPlayer();

public:
	void		Set_Money(int _iMoney) { m_tInfo.iMoney += _iMoney; }
	void		Equip_Item(CObj* pItem);
	void		Unequip_Item(CObj* pItem);
	void		Item_Ability(int _iAttack, int _iHp);

public:
	virtual void		Render() override;
	virtual void		Set_Hp(int _iHp) override { m_tInfo.iHp = _iHp; }
	virtual void		SelectJob() override;

private:
	CObj*			m_pItemSlot[IT_END];
};

