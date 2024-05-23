#include "stdafx.h"
#include "PointColliderComponent.h"
#include "RenderMgr.h"

CPointColliderComponent::CPointColliderComponent(ComponentType _eComponentType):
	CColliderComponent(_eComponentType)
{
	m_eColliderType = ColliderType::Point;
}

CPointColliderComponent::~CPointColliderComponent()
{
}

void CPointColliderComponent::Render()
{
	//RENDER.DrawEllipse({ (long)m_tPrevPointPos.x - 2,(long)m_tPrevPointPos.y - 2,(long)m_tPrevPointPos.x + 2,(long)m_tPrevPointPos.y + 2 });
	//RENDER.DrawEllipse({ (long)m_tCurPointPos.x - 2,(long)m_tCurPointPos.y - 2,(long)m_tCurPointPos.x + 2,(long)m_tCurPointPos.y + 2 });
}


