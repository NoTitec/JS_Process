#include "stdafx.h"
#include "KHR_Scene.h"
#include "KHR_LineMgr.h"
#include "KHR_Player.h"

#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CKHR_Scene::CKHR_Scene()
{
}

CKHR_Scene::~CKHR_Scene()
{
}

void CKHR_Scene::Initialize()
{
	BMP.Insert_Bmp(L"../Image/KHR/KHR_Stage.bmp", L"KHR_Stage");	
	BMP.Insert_Bmp(L"../Image/KHR/KHR_Sample_Real.bmp", L"KHR_Stage_Back");

	KHR_Line.Initialize();
}

int CKHR_Scene::Update()
{
	return 0;
}

void CKHR_Scene::Late_Update()
{
	SCROLL.Scroll_Lock(KHR_MAPCX, KHR_MAPCY);
}

void CKHR_Scene::Render(HDC hDC)
{
	int iScroll = SCROLL.Get_ScrollX();

	HDC hMemDC_Back = BMP.Find_Img(L"KHR_Stage_Back");
	HDC hMemDC = BMP.Find_Img(L"KHR_Stage");
	
	BitBlt(hDC, iScroll * 0.5f, 0, 4200, WINCY, hMemDC_Back, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,
		iScroll,
		0,
		4200,
		WINCY,
		hMemDC,
		0, 0,
		4200,
		WINCY,
		RGB(0, 0, 0));

	KHR_Line.Render(hDC);
}

void CKHR_Scene::Release()
{
}

void CKHR_Scene::Start()
{
	CObj* pPlayer = CAbstractFactory<CKHR_Player>::Create();
	OBJ.Add_Object(OBJ_PLAYER, pPlayer);
}
