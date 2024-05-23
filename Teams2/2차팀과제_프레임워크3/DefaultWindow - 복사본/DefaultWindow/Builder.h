#pragma once
#include "Define.h"

template<typename ReturnType>
class CBuilder
{
public:
	virtual ~CBuilder() {}

public:
	virtual ReturnType* Build() PURE;
};

