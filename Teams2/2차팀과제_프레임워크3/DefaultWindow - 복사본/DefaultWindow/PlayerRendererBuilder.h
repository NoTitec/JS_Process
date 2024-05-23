#pragma once
#include "Builder.h"
#include "Component.h"
class CPlayerRendererBuilder :public CBuilder<CComponent>
{
public:
	CPlayerRendererBuilder();
	virtual ~CPlayerRendererBuilder() override;

public:
	CComponent* Build() override;

};

