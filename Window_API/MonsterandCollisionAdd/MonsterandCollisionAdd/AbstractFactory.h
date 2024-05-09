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
	static CObj* Create(float fX, float fY, DIRECTION eDir)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);
		pObj->Set_Direction(eDir);

		return pObj;
	}
};

