#pragma once

#include "Obj.h"

//��� ������Ʈ�� �����ϴ� �޵���Ʈ+�̱��� ���� Ŭ����

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	void		Add_Object(OBJ_ID eID, CObj* pObj);
	CObj*		Get_Nearest_Object(OBJ_ID eID, float _fX, float _fY);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CObjMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	list<CObj*>		m_ObjList[OBJ_END];
	static CObjMgr* m_pInstance;
};
