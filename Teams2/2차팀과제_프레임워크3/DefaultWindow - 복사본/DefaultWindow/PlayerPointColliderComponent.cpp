#include "stdafx.h"
#include "PlayerPointColliderComponent.h"
#include "LineColliderComponent.h"
#include "HGH_CollisionMgr.h"
#include "PlayerFSMComponent.h"
#include "PlayerOnLineState.h"
CPlayerPointColliderComponent::CPlayerPointColliderComponent(ComponentType _eComponentType):
	CPointColliderComponent::CPointColliderComponent(_eComponentType)
{
}

CPlayerPointColliderComponent::~CPlayerPointColliderComponent()
{
}

void CPlayerPointColliderComponent::Init()
{
	HGH_COLLISION.Push_Back_Collider(this);
	m_tCurPointPos = m_pOwner->m_tPos + Vec2F{ 0.f, m_pOwner->m_tScale.y };
}

void CPlayerPointColliderComponent::Update()
{
	//m_tPrevPointPos = m_pOwner->m_tPos + Vec2F{ 0.f, m_pOwner->m_tScale.y };
}

void CPlayerPointColliderComponent::Late_Update()
{
	m_tPrevPointPos = m_tCurPointPos;
	m_tCurPointPos = m_pOwner->m_tPos + Vec2F{ 0.f, m_pOwner->m_tScale.y };
}


void CPlayerPointColliderComponent::On_Collision(CColliderComponent* _pOtherCollider)
{
	ColliderType eOtherColliderType{ _pOtherCollider->Get_Collider_Type() };

	if (eOtherColliderType == ColliderType::Line)
	{
		CLineColliderComponent* pLineCollider{ static_cast<CLineColliderComponent*>(_pOtherCollider) };
		LineType eLineType{ pLineCollider->Get_Line_Type() };

		switch (eLineType)
		{
		case LineType::Push_Up_Line:
			On_Push_Up_Line(pLineCollider);
			break;
		}
	}
}

void CPlayerPointColliderComponent::On_Push_Up_Line(CLineColliderComponent* _pLineCollider)
{
	CComponent* pComponent{ m_pOwner->Get_Component(ComponentType::PlayerFSM) };
	if (pComponent != nullptr)
	{
		CPlayerFSMComponent* pPlayerFSMComponent{ static_cast<CPlayerFSMComponent*>(pComponent) };
		if (pPlayerFSMComponent->m_eStateType != PlayerState::OnLine)
		{
			static_cast<CPlayerOnLineState*>(pPlayerFSMComponent->m_pStateArray[E2I(PlayerState::OnLine)])->Set_Connected_Line(_pLineCollider->Get_Line());
			pPlayerFSMComponent->m_pState->Change_State_To(PlayerState::OnLine);
		}
	}
}
