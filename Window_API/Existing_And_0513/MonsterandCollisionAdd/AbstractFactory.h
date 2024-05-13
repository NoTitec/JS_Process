#pragma once
#include "Obj.h"

//상속관계 클래스들의 공통 코드를 통합하는 팩토리 static 클래스

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
	//총알생성
	static CObj* Create(float fX, float fY, DIRECTION eDir=DIR_END)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Direction(eDir);

		return pObj;
	}
	//각도총알생성
	static CObj* Create(float fX, float fY, float _fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Angle(_fAngle);
		return pObj;
	}
};

