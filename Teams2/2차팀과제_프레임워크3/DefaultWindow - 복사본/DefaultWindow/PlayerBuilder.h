#pragma once
#include "Builder.h"
#include "Object.h"

class CPlayerBuilder :public CBuilder<CObject>
{
public:
	CPlayerBuilder();
	virtual ~CPlayerBuilder() override;

public:
	virtual CObject* Build() override;

};


