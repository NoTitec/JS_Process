#include "stdafx.h"
#include "PlayerFSMBuilder.h"
#include "PlayerFSMComponent.h"
CComponent* CPlayerFSMBuilder::Build()
{
	CComponent* pPlayerStateMachineComponent{ new CPlayerFSMComponent(ComponentType::PlayerFSM) };

	return pPlayerStateMachineComponent;
}
