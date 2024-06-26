#pragma once

#include "Obj.h"


class CObjMgr
{
	DECLARE_SINGLE(CObjMgr)


public:
	void				Update();
	void				Late_Update();
	void				Render(HDC hDC);


public:
	void				Delete_ID(OBJ_ID eID);

public:
	void				Add_Object(OBJ_ID eID, CObj* pObj);
	// void				Add_Object(OBJ_ID eID, CObj* pObj, Vec2 pos);


private:
	list<CObj*>			m_ObjList[OBJ_END];
};

