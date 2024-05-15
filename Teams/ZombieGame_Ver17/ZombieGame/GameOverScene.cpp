#include "pch.h"
#include "SceneMgr.h"
#include "GameOverScene.h"

CGameOverScene::CGameOverScene()
{
}

CGameOverScene::~CGameOverScene()
{
	Release();
}

void CGameOverScene::Initialize()
{

}

int CGameOverScene::Update()
{
	return 0;
}

void CGameOverScene::Late_Update()
{
	if (GetAsyncKeyState('X') & 0x0001)
	{
		CSceneMgr::Change_Active_Scene(SCENE_TYPE::MAIN_MENU_SCENE);
	}
}

void CGameOverScene::Render(HDC _hdc)
{
	HBRUSH blackBrush = ::CreateSolidBrush(RGB(16, 16, 16));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, blackBrush);
	::Rectangle(_hdc, 0, 0, WINCX, WINCY);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(blackBrush);

	HFONT titleFont = CreateFont(75, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±Ã¼­"));
	HFONT oldTitleFont = (HFONT)::SelectObject(_hdc, titleFont);

	::TextOut(_hdc, 55, 100, L"À¯¾È´ÔÀÌ Á×¾ú½À´Ï´Ù", 10);
	::SelectObject(_hdc, titleFont);
	::DeleteObject(oldTitleFont);

	HFONT descriptionFont = CreateFont(35, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±Ã¼­"));
	HFONT oldDescriptionFont = (HFONT)::SelectObject(_hdc, descriptionFont);

	::TextOut(_hdc, 225, WINCY - 100, L"Press X Button", 14);
	::SelectObject(_hdc, oldDescriptionFont);
	::DeleteObject(descriptionFont);
}

void CGameOverScene::Release()
{
}
