#include "stdafx.h"
#include "RectangleRendererBuilder.h"
#include "RectangleRendererComponent.h"

CRectangleRendererBuilder::CRectangleRendererBuilder()
{
}

CRectangleRendererBuilder::~CRectangleRendererBuilder()
{
}

CComponent* CRectangleRendererBuilder::Build()
{
    CRectangleRendererComponent* pRRC = new CRectangleRendererComponent(ComponentType::RectangleRenderer);
    return pRRC;
}
