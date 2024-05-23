#include "stdafx.h"
#include "LineColliderComponent.h"
#include "RenderMgr.h"

CLineColliderComponent::CLineColliderComponent(ComponentType _eComponentType):
	CColliderComponent::CColliderComponent(_eComponentType)
{
	m_eColliderType = ColliderType::Line;
}

CLineColliderComponent::~CLineColliderComponent()
{
}

void CLineColliderComponent::Render()
{
	RENDER.DrawLine(m_tLine);
}

