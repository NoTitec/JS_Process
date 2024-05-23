#include "stdafx.h"
#include "KJW_Scene.h"
#include "KJW_LineMgr.h"
#include "KJW_Player.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"

CKJW_Scene::CKJW_Scene()
{
}

CKJW_Scene::~CKJW_Scene()
{
	Release();
}

void CKJW_Scene::Initialize()
{
	KJW_LINE.Initialize();
	OBJ.Add_Object(OBJ_PLAYER, CAbstractFactory<CKJW_Player>::Create());
	BMP.Insert_Bmp(L"../Image/KJW_Ground.bmp", L"Ground");
}

void CKJW_Scene::Start()
{

}

int CKJW_Scene::Update()
{
	return 0;
}

void CKJW_Scene::Late_Update()
{
}

void CKJW_Scene::Render(HDC hDC)
{
	HDC hGroundDC = BMP.Find_Img(L"Ground");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hGroundDC, 0, 0, SRCCOPY);
	KJW_LINE.Render(hDC);
}

void CKJW_Scene::Release()
{
}

