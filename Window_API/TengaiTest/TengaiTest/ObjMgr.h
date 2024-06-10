#pragma once

#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	void Set_Player_DeadTime() { m_dwPlayerDeadTime = GetTickCount(); }
	DWORD Get_Player_DeadTime() { return m_dwPlayerDeadTime; }
	CObj*		Get_Target(OBJ_ID eID, CObj* pObj);
	CObj* Get_Target_Within_Certain_Distance(OBJ_ID eID, CObj* pObj,float distance);
	CObj* Get_Near_Target_BossMonster_Monster(OBJ_ID eID, OBJ_ID eID2, CObj* pObj);
	CObj* Get_Player_Pointer()
	{
		return m_ObjList[OBJ_PLAYER].front();
	}
	CObj* Get_Pet_Pointer()
	{
		return m_ObjList[OBJ_PET].front();
	}
	void		Delete_ID(OBJ_ID eID);
	void		Delete_All();
	bool		Check_ID_Empty(OBJ_ID eID)
	{
		if (m_ObjList[eID].empty())
			return true;
		else
			return false;
	};

	list<CObj*> Get_ID_List(OBJ_ID _eObjId) { return m_ObjList[_eObjId]; }
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
	DWORD dwSaveTime;
	DWORD m_dwPlayerDeadTime;
};

#define ObjMgr CObjMgr::Get_Instance()