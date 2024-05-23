#pragma once
#include "Builder.h"
#include "Object.h"
class CLineBuilder :public CBuilder<CObject>
{
public:
	CLineBuilder();
	virtual ~CLineBuilder() override;

public:
	virtual CObject* Build() override;
};

