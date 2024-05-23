#include "stdafx.h"
#include "PushUpLineColliderComponent.h"
#include "PointColliderComponent.h"
#include "KeyMgr.h"
#include "PlayerFSMComponent.h"

CPushUpLineColliderComponent::CPushUpLineColliderComponent(ComponentType _eComponentType):
	CLineColliderComponent::CLineColliderComponent(_eComponentType)
{
	m_eLineType = LineType::Push_Up_Line;
}

CPushUpLineColliderComponent::~CPushUpLineColliderComponent()
{
}

void CPushUpLineColliderComponent::On_Collision(CColliderComponent* _pOtherCollider)
{
	ColliderType eOtherColliderType{ _pOtherCollider->Get_Collider_Type() };
	switch (eOtherColliderType)
	{
	case ColliderType::Point:
		_pOtherCollider->Get_Owner()->m_tPos = (static_cast<CPointColliderComponent*>(_pOtherCollider))->Get_Projection_Pos();
		break;
	}
}
