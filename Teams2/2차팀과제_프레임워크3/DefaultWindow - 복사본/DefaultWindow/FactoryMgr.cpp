#include "stdafx.h"
#include "FactoryMgr.h"
#include "PlayerBuilder.h"
#include "RectangleRendererBuilder.h"
#include "PlayerFSMBuilder.h"
#include "LineBuilder.h"
#include "PushUpLineColliderBuilder.h"
#include "PlayerPointColliderBuilder.h"
#include "PlayerRendererBuilder.h"

CFactoryMgr::CFactoryMgr()
{
}

CFactoryMgr::~CFactoryMgr()
{
	Release();
}

void CFactoryMgr::Initialize()
{
	Init_Component_Factory();
	Init_Object_Factory();
}

void CFactoryMgr::Release()
{
}

void CFactoryMgr::Init_Object_Factory()
{
	m_tObjectFactory.Insert_Builder(ObjectType::Player, new CPlayerBuilder);
	m_tObjectFactory.Insert_Builder(ObjectType::Line, new CLineBuilder);
}

void CFactoryMgr::Init_Component_Factory()
{
	m_tComponentFactory.Insert_Builder(ComponentType::RectangleRenderer, new CRectangleRendererBuilder);
	m_tComponentFactory.Insert_Builder(ComponentType::PlayerFSM, new CPlayerFSMBuilder);
	m_tComponentFactory.Insert_Builder(ComponentType::PushUpLineCollider, new CPushUpLineColliderBuilder);
	m_tComponentFactory.Insert_Builder(ComponentType::PlayerPointCollider, new CPlayerPointColliderBuilder);
	m_tComponentFactory.Insert_Builder(ComponentType::PlayerRenderer, new CPlayerRendererBuilder);
}

CObject* CFactoryMgr::Build_Object(ObjectType _eObjectType)
{
	return m_tObjectFactory.Build(_eObjectType);
}

CComponent* CFactoryMgr::Build_Component(ComponentType _eComponentType, CObject* _pOwner)
{
	CComponent* pComponent{ m_tComponentFactory.Build(_eComponentType) };
	// Set_Owner, Init 순서 중요 <- Init에서 각 컴포넌트의 m_pOwner가 nullptr이 되지 않도록
	pComponent->Set_Owner(_pOwner);
	pComponent->Init();
	return pComponent;
}
