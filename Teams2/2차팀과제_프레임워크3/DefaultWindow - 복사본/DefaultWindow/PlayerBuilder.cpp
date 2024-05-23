#include "stdafx.h"
#include "PlayerBuilder.h"
#include "RectangleRendererComponent.h"
#include "FactoryMgr.h"
#include "BmpMgr.h"
#include "PlayerRenedererComponent.h"
CPlayerBuilder::CPlayerBuilder()
{
}

CPlayerBuilder::~CPlayerBuilder()
{
}

CObject* CPlayerBuilder::Build()
{
	CObject* pPlayer{ new CObject(ObjectType::Player)};
	pPlayer->Initialize();
	pPlayer->m_tPos = { 200.f, 400.f };
	pPlayer->m_tScale = { 30.f, 30.f };
	pPlayer->m_tSpeed = { 5.f, 5.f };
	pPlayer->m_tUnitDirection = { 1.f,0.f };

	//pPlayer->Push_Back_Component(BUILD_COMPONENT(ComponentType::RectangleRenderer, pPlayer));
	pPlayer->Push_Back_Component(BUILD_COMPONENT(ComponentType::PlayerRenderer, pPlayer));
	pPlayer->Push_Back_Component(BUILD_COMPONENT(ComponentType::PlayerFSM, pPlayer));
	pPlayer->Push_Back_Component(BUILD_COMPONENT(ComponentType::PlayerPointCollider, pPlayer));

	BMP.Insert_Bmp(L"../Image/KJW_Chr001.bmp", L"HGH_Player");
	return pPlayer;
}
