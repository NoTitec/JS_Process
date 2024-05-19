#pragma once

#include "Obj.h"

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
	static CObj* Create(float fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Angle(fAngle);

		return pObj;
	}
	static CObj* Create(float fX, float fY)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);

		return pObj;
	}
};