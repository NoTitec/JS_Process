#pragma once

#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	CObj*		Get_Target(OBJ_ID eID, CObj* pObj);
	CObj* Get_Player_Pointer()
	{
		return m_ObjList[OBJ_PLAYER].front();
	}
	void		Delete_ID(OBJ_ID eID);

public:
	void		Add_Object(OBJ_ID eID, CObj* pObj);
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
	//list<CObj*>		m_RenderList[RENDER_END];
	static CObjMgr* m_pInstance;

};

#define ObjMgr CObjMgr::Get_Instance()