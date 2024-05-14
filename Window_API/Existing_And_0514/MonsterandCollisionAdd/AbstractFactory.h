#pragma once
#include "Obj.h"

//��Ӱ��� Ŭ�������� ���� �ڵ带 �����ϴ� ���丮 static Ŭ����

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
	//�Ѿ˻���
	static CObj* Create(float fX, float fY, DIRECTION eDir=DIR_END)
	{
		CObj* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Initialize();
		pObj->Set_Direction(eDir);

		return pObj;
	}
	//�����Ѿ˻���
	static CObj* Create(float fX, float fY, float _fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Angle(_fAngle);
		return pObj;
	}
};
