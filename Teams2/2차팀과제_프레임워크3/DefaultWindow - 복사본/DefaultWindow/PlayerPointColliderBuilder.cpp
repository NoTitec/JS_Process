#include "stdafx.h"
#include "PlayerPointColliderBuilder.h"
#include "PlayerPointColliderComponent.h"
CComponent* CPlayerPointColliderBuilder::Build()
{
    CComponent* pPlayerPointColliderComponent{ new CPlayerPointColliderComponent(ComponentType::PlayerPointCollider) };

    return pPlayerPointColliderComponent;
}
