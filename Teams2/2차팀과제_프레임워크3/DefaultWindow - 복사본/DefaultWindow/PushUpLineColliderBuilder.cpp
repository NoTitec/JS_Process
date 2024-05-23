#include "stdafx.h"
#include "PushUpLineColliderBuilder.h"
#include "PushUpLineColliderComponent.h"
CPushUpLineColliderBuilder::CPushUpLineColliderBuilder()
{
}

CPushUpLineColliderBuilder::~CPushUpLineColliderBuilder()
{
}

CComponent* CPushUpLineColliderBuilder::Build()
{
	return new CPushUpLineColliderComponent(ComponentType::PushUpLineCollider);
}
