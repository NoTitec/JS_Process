#pragma once

#include "Obj.h"
class CObj;
class CItem : public CObj
{
public:
	CItem();
	virtual ~CItem();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

public:
	void Set_Item_Type(OBJ_ITEM_TYPE _eItemType) { m_iType = _eItemType; }
	void Set_Target(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	OBJ_ITEM_TYPE Get_Item_Type() { return (OBJ_ITEM_TYPE)m_iType; }

private:
	CObj* m_pPlayer;
};

