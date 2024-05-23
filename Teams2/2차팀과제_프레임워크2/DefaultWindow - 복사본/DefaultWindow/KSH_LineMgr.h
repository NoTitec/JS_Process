#pragma once
#include "Singleton.h"
#include "Line.h"
class CKSH_LineMgr : public CSingleton< CKSH_LineMgr>
{
	friend CSingleton<CKSH_LineMgr>;
	CKSH_LineMgr();
	~CKSH_LineMgr();
public:
	void		Initialize();
	void		Render(HDC hDC);
	void		Release();

public:
	bool		Collision_Line(float fX, float* pY);
	void		Load_Line();

public:
	

private:
	list<CLine*>		m_LineList;
};

#define	KSH_LINE CKSH_LineMgr::Get_Instance()

