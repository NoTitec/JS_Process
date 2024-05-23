#pragma once
#include "Builder.h"
#include "Component.h"

class CPushUpLineColliderBuilder :public CBuilder<CComponent>
{
public:
	CPushUpLineColliderBuilder();
	virtual ~CPushUpLineColliderBuilder() override;

public:
	virtual CComponent* Build() override;
};

