#include "stdafx.h"
#include "PlayerRendererBuilder.h"
#include "PlayerRenedererComponent.h"

CPlayerRendererBuilder::CPlayerRendererBuilder()
{
}

CPlayerRendererBuilder::~CPlayerRendererBuilder()
{
}

CComponent* CPlayerRendererBuilder::Build()
{
    return new CPlayerRenedererComponent(ComponentType::PlayerRenderer);
}
