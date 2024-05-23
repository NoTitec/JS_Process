#pragma once
#include "Define.h"
#include "Builder.h"
#include "Component.h"
class CRectangleRendererBuilder :public CBuilder<CComponent>
{
public:
	CRectangleRendererBuilder();
	virtual ~CRectangleRendererBuilder() override;

public:
	virtual CComponent* Build() override;
};

