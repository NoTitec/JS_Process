#include "pch.h"
#include "SceneMgr.h"
#include "MainMenuScene.h"

void CMainMenuScene::Initialize()
{
	
}

int CMainMenuScene::Update()
{
	if (GetAsyncKeyState('Y') & 0x0001)
	{
		CSceneMgr::Change_Active_Scene(1);
	}
	return 0;
}

void CMainMenuScene::Late_Update()
{
	
}

void CMainMenuScene::Render(HDC _hdc)
{
	HBRUSH blackBrush = ::CreateSolidBrush(RGB(16, 16, 16));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, blackBrush);
	::Rectangle(_hdc, 0, 0, WINCX, WINCY);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(blackBrush);

	HFONT titleFont = CreateFont(75, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
	HFONT oldTitleFont = (HFONT)::SelectObject(_hdc, titleFont);

	::TextOut(_hdc, 120, 100, L"나는 엄유안이다", 8);
	::SelectObject(_hdc, titleFont);
	::DeleteObject(oldTitleFont);
	
	HFONT descriptionFont = CreateFont(35, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
	HFONT oldDescriptionFont = (HFONT)::SelectObject(_hdc, descriptionFont);

	::TextOut(_hdc, 225, WINCY - 100, L"Press Y Button", 14);
	::SelectObject(_hdc, oldDescriptionFont);
	::DeleteObject(descriptionFont);
}

void CMainMenuScene::Release()
{

}
