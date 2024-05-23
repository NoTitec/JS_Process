#pragma once

#include "Define.h"
#include "MyBmp.h"
#include "Singleton.h"
#include <map>


class CBmpMgr : public CSingleton<CBmpMgr>
{
	friend CSingleton<CBmpMgr>;
private:
	CBmpMgr();
	~CBmpMgr();

public:
	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC			Find_Img(const TCHAR* pImgKey);
	void		Release();

private:
	static CBmpMgr*	m_pInstance;
	map<const TCHAR*, CMyBmp*>		m_mapBit;
};

#define BMP CBmpMgr::Get_Instance()