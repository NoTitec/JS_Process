#include "pch.h"
#include "UIMgr.h"

#include "Combo.h"
#include "Skill.h"

CObj* CUIMgr::pTarget = nullptr;
vector<CUI*> CUIMgr::uis = {};

CUIMgr::CUIMgr()
{
	
}

CUIMgr::~CUIMgr()
{
	Release();
}

void CUIMgr::Initialize()
{
	
	for (auto& ui : uis)
	{
		ui->Initialize();
	}
}

void CUIMgr::Update()
{
	for (auto& ui : uis)
	{
		ui->Update();
	}
}

void CUIMgr::Late_Update()
{
	for (auto& ui : uis)
	{
		ui->Late_Update();
	}
}

void CUIMgr::Render()
{
	for (auto& ui : uis)
	{
		ui->Render();
	}
}

void CUIMgr::Release()
{
	for (auto& ui : uis)
	{
		ui->Release();
	}
}
