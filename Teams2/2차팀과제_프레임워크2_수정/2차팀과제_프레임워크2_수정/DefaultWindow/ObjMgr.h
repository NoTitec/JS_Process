#pragma once
#include "Singleton.h"
#include "Obj.h"


class CObjMgr : public CSingleton<CObjMgr>
{
friend CSingleton<CObjMgr>;
private:
	CObjMgr();
	virtual ~CObjMgr();

public:
	CObj*		Get_Target(OBJ_ID eID, CObj* pObj);

public:
	void			Add_Object(OBJ_ID eID, CObj* pObj);
	void			Update();
	void			Late_Update();
	void			Render(HDC hDC);
	void			Release();

	void			RemoveObjects();

private:
	list<CObj*>		m_ObjList[OBJ_END];
	static CObjMgr*	m_pInstance;
};

#define OBJ CObjMgr::Get_Instance()
