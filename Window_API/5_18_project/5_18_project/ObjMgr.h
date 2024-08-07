#pragma once
#include "stdafx.h"
#include "Obj.h"
class CObjMgr
{
//private:
//	CObjMgr();
//	~CObjMgr();
//
//public:
//	void		Add_Object(OBJ_ID eID, CObj* pObj);
//	void		Update();
//	void		Late_Update();
//	void		Render(HDC hDC);
//	void		Release();
//
//public:
//	CObj* Get_Player();
//	CObj* Get_Target(OBJ_ID eID, CObj* pObj);
//
//public:
//	static CObjMgr* Get_Instance()
//	{
//		if (!m_pInstance)
//			m_pInstance = new CObjMgr;
//
//		return m_pInstance;
//	}
//
//	static void		Destroy_Instance()
//	{
//		if (m_pInstance)
//		{
//			delete m_pInstance;
//			m_pInstance = nullptr;
//		}
//	}
//
//	void		Delete_ID(OBJ_ID eID);
//private:
//	list<CObj*>		m_ObjList[OBJ_END];
//	static CObjMgr* m_pInstance;
//	HDC			m_DC;
private:
	CObjMgr();
	~CObjMgr();

public:
	CObj* Get_Target(OBJ_ID eID, CObj* pObj);
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
	static CObjMgr* m_pInstance;
};

