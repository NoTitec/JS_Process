#pragma once
#include "Obj.h"
#include "UI.h"
template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create(float fX, float fY, DIRECTION eDir = DIR_END)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Direction(eDir);

		return pObj;
	}
	static CObj* Create(float fX, float fY, float Angle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Angle(Angle);
		return CObj;
	}
	static CUI* Create_UI()
	{
		CUI* pUI = new T;
		pUI->Initialize();
		return pUI;
	}
	static CUI* Create_UI(float fX, float fY)
	{
		CUI* pUI = new T;
		pUI->Initialize();
		pUI->Set_Pos(fX, fY);
		return pUI;
	}
	static CUI* Create_UI(float fX, float fY, CObj* OwnerPointer)
	{
		CUI* pUI = new T;
		pUI->Initialize();
		pUI->Set_Pos(fX,fY);
		pUI->Set_Owner(OwnerPointer);
		return pUI;
	}
};
