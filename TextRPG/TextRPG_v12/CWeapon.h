#pragma once
#include "ItemBase.h"
class CWeapon final :public ItemBase
{
public:
	CWeapon();
	CWeapon(const CWeapon& rhs);
	CWeapon(const char* _pname, int _iattack, int _ihp, int _imoney);
	virtual ~CWeapon();

	virtual void Render() override;
	virtual ITEMTYPE			Get_Type() override;
	virtual void	Set_Type(ITEMTYPE eType) override;
	virtual	EQUIPSTATE	Get_State() override;
	virtual void	Set_State(EQUIPSTATE eTate) override;

private:
	ITEMTYPE e_type;
	EQUIPSTATE e_state;
};

