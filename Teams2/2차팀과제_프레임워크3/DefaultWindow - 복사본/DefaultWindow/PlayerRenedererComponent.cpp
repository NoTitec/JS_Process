#include "stdafx.h"
#include "PlayerRenedererComponent.h"
#include "RenderMgr.h"
#include "BmpMgr.h"
#include "Object.h"
CPlayerRenedererComponent::CPlayerRenedererComponent(ComponentType _eCompoonentType):
	CComponent::CComponent(_eCompoonentType)
{

}

CPlayerRenedererComponent::~CPlayerRenedererComponent()
{
}

void CPlayerRenedererComponent::Init()
{
}

void CPlayerRenedererComponent::Update()
{
}

void CPlayerRenedererComponent::Late_Update()
{
}

void CPlayerRenedererComponent::Render()
{
	RENDER.DrawBMP(BMP.Find_Img(L"HGH_Player"),
		{ 
			(long)m_pOwner->m_tPos.x - (long)m_pOwner->m_tScale.x,
			(long)m_pOwner->m_tPos.y - (long)m_pOwner->m_tScale.y,
			(long)m_pOwner->m_tPos.x + (long)m_pOwner->m_tScale.x,
			(long)m_pOwner->m_tPos.y + (long)m_pOwner->m_tScale.y 
		},
		{		
			0,100,100,200
		},
		BLUEGREEN
	);
}

void CPlayerRenedererComponent::Release()
{
}
