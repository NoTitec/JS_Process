#include "stdafx.h"
#include "ColliderComponent.h"
#include "Object.h"
#include "RenderMgr.h"
#include "HGH_CollisionMgr.h"
CColliderComponent::CColliderComponent(ComponentType _eComponentType):
	CComponent(_eComponentType)
{
}

CColliderComponent::~CColliderComponent()
{
}

void CColliderComponent::Init()
{
	HGH_COLLISION.Push_Back_Collider(this);
}

void CColliderComponent::Update()
{
}

void CColliderComponent::Late_Update()
{
}

void CColliderComponent::Render()
{
}

void CColliderComponent::Release()
{
	HGH_COLLISION.Pop_Back_Collider(this);
}
