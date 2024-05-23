#include "stdafx.h"
#include "RectangleRendererComponent.h"
#include "Object.h"
#include "RenderMgr.h"

CRectangleRendererComponent::CRectangleRendererComponent(ComponentType _eComponentType):
	CComponent::CComponent(_eComponentType)
{
}

CRectangleRendererComponent::~CRectangleRendererComponent()
{
	Release();
}

void CRectangleRendererComponent::Init()
{
}

void CRectangleRendererComponent::Update()
{
}

void CRectangleRendererComponent::Late_Update()
{
}

void CRectangleRendererComponent::Render()
{
	RENDER.DrawRect({
		(long)m_pOwner->m_tPos.x-(long)m_pOwner->m_tScale.x,
		(long)m_pOwner->m_tPos.y-(long)m_pOwner->m_tScale.y,
		(long)m_pOwner->m_tPos.x+(long)m_pOwner->m_tScale.x,
		(long)m_pOwner->m_tPos.y+(long)m_pOwner->m_tScale.y
		});
}

void CRectangleRendererComponent::Release()
{
}
