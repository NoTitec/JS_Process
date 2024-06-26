#include "stdafx.h"
#include "BmpMgr.h"

CBmpMgr* CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{

}

CBmpMgr::~CBmpMgr()
{

}

void CBmpMgr::Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
}

HDC CBmpMgr::Find_Img(const TCHAR* pImgKey)
{
    return HDC();
}

void CBmpMgr::Release()
{
}
