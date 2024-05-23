#include "stdafx.h"
#include "Scene1.h"
#include "LineMgr.h"

CScene1::~CScene1()
{
    Release();
}



void CScene1::Initialize()
{
    CLineMgr::Get_Instance()->Initialize();
}

void CScene1::Start()
{

    
}

int CScene1::Update()
{

    return 0;
}
void CScene1::Late_Update()
{
   
}

void CScene1::Render(HDC hDC)
{
    CLineMgr::Get_Instance()->Render(hDC);
}

void CScene1::Release()
{

}


