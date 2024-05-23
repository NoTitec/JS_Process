#pragma once
#include "Singleton.h"
#include "Line.h"

class CKJW_LineMgr : public CSingleton< CKJW_LineMgr>
{
friend CSingleton<CKJW_LineMgr>;
public:
	CKJW_LineMgr();
	~CKJW_LineMgr();

	void		Initialize();
	void		Render(HDC hDC);
	void		Release();

	void		Load_Lines();

	CLine*		Get_Current_Line(Point2F _tPoint,float& _fYSol);
	float		Get_Floor_Y(Point2F _tPoint);
	float		Get_Line_Y_Solution(CLine* _pLine, float fX);

	float		Get_Wall_X(Point2F _tPoint, bool _bRight);
	float		Get_Line_X_Solution(CLine* _pLine, float fY);
private:
	list<CLine*>		m_LineList;
};

#define	KJW_LINE CKJW_LineMgr::Get_Instance()