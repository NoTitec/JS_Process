#include "stdafx.h"
#include "Component.h"
#include "Object.h"
int CComponent::s_iComponentID{};

CComponent::CComponent(ComponentType _eComponentType) :
	m_eComponentType{ _eComponentType }
{
}

CComponent::~CComponent()
{
}

ObjectType CComponent::Get_Owner_Type()
{
	return m_pOwner->Get_Type();
}
