#pragma once
#include "Builder.h"
#include "Component.h"
class CPlayerFSMBuilder :public CBuilder<CComponent>
{
public:
	CComponent* Build() override;
};

