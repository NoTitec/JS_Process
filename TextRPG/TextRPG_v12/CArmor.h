#pragma once
#include "ItemBase.h"

class CArmor final :public ItemBase
{
public:
	CArmor();
	CArmor(const CArmor& rhs);
	CArmor(const char* _pname, int _iattack, int _ihp, int _imoney);
	virtual ~CArmor();

	virtual void Render() override;
	virtual ITEMTYPE			Get_Type() override;
	virtual void	Set_Type(ITEMTYPE eType) override;
	virtual	EQUIPSTATE	Get_State() override;
	virtual void	Set_State(EQUIPSTATE eTate) override;

private:
	ITEMTYPE e_type;
	EQUIPSTATE e_state;
};