#pragma once

#include "Define.h"


class CObj;

class CColMgr
{
	DECLARE_SINGLE(CColMgr)
	

public:
	static	void		Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	static	bool		Check_Rect(CObj* _Dst, CObj* _Src);



};

