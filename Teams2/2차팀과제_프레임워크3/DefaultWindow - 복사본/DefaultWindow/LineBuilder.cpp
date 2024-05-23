#include "stdafx.h"
#include "LineBuilder.h"
#include "FactoryMgr.h"
CLineBuilder::CLineBuilder()
{
}

CLineBuilder::~CLineBuilder()
{
}

CObject* CLineBuilder::Build()
{
    CObject* pLine{ new CObject(ObjectType::Line) };

    CComponent* pLineCollider{ BUILD_COMPONENT(ComponentType::PushUpLineCollider, pLine) };
    pLine->Push_Back_Component(pLineCollider);


    return pLine;
}
