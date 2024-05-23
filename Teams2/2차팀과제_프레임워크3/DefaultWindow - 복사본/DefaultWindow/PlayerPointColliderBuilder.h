#pragma once
#include "Builder.h"
#include "Component.h"
class CPlayerPointColliderBuilder :public CBuilder<CComponent>
{
public:
	CComponent* Build() override;
};

