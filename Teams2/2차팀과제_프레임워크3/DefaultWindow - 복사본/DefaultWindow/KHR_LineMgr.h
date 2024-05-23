#pragma once
#include "Singleton.h"
#include "KHR_Line.h"

class CKHR_LineMgr
	: public CSingleton<CKHR_LineMgr>
{
	friend CSingleton<CKHR_LineMgr>;

private:
	CKHR_LineMgr();
	virtual ~CKHR_LineMgr() override;

public:
	void		Initialize();
	void		Render(HDC hDC);
	void		Release();

public:
	bool		Collision_Line(float _fX, float _fY, float* _pY);

	void		Save_Line();
	void		Load_Line();

private:
	list<CKHR_Line*>			m_LineList;
	static CKHR_LineMgr*	m_pInstance;
};

#define KHR_Line CKHR_LineMgr::Get_Instance()

