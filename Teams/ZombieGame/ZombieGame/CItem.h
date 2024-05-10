#pragma once

#include "Obj.h"
class CItem : public CObj
{
public:
	CItem();
	virtual ~CItem();
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
public:
	void Set_Item_Type(OBJ_ITEM_TYPE _eItemType) { m_eItemType = _eItemType; }
	OBJ_ITEM_TYPE Get_Item_Type() { return m_eItemType; }
private:
	OBJ_ITEM_TYPE m_eItemType;
};

