#include "stdafx.h"
#include "PlayerFSMComponent.h"
#include "RenderMgr.h"
#include "Object.h"
#include "PlayerOnLineState.h"
#include "Component.h"
#include "PlayerJumpingState.h"
#include "PlayerDownJumpingState.h"
CPlayerFSMComponent::CPlayerFSMComponent(ComponentType _eComponentType):
	CFSMComponent<PlayerState>::CFSMComponent(_eComponentType)
{
}

CPlayerFSMComponent::~CPlayerFSMComponent()
{

}

void CPlayerFSMComponent::Init()
{
	m_pStateArray[E2I(PlayerState::OnLine)] = new CPlayerOnLineState(m_pOwner, this);
	m_pStateArray[E2I(PlayerState::Jumping)] = new CPlayerJumpingState(m_pOwner, this);
	m_pStateArray[E2I(PlayerState::DownJumping)] = new CPlayerDownJumpingState(m_pOwner, this);
	for (auto pPlayerState : m_pStateArray)
	{
		pPlayerState->Init();
	}

	m_pState = m_pStateArray[E2I(PlayerState::DownJumping)];
	m_pState->Enter_State_To(PlayerState::DownJumping);
}

void CPlayerFSMComponent::Render()
{
}
