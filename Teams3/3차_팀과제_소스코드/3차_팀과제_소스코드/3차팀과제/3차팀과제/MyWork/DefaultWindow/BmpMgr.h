#pragma once

#include "Define.h"

#include <map>


class CBmpMgr
{
	DECLARE_SINGLE(CBmpMgr)

public:
	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC			Find_Img(const TCHAR* pImgKey);
	void		Release();

private:
	//map<const TCHAR*, CMyBmp*>		m_mapBit;

};

