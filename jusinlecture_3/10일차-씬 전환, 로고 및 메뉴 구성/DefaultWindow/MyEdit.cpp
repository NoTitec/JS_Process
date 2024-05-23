#include "stdafx.h"
#include "MyEdit.h"
#include "BmpMgr.h"


CMyEdit::CMyEdit()
{
}


CMyEdit::~CMyEdit()
{
	Release();
}

void CMyEdit::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Edit/Tile", L"Tile");
}

int CMyEdit::Update()
{
	return 0;
}

void CMyEdit::Late_Update()
{
}

void CMyEdit::Render(HDC hDC)
{
}

void CMyEdit::Release()
{
}
