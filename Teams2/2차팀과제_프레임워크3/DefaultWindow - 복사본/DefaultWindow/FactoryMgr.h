#pragma once
#include "Define.h"
#include "Singleton.h"
#include "Factory.h"
#include "Builder.h"
#include "Object.h"
#include "Component.h"

class CFactoryMgr :public CSingleton<CFactoryMgr>
{
	using ObjectFactory		= CFactory<CObject, CBuilder<CObject>, ObjectType>;
	using ComponentFactory	= CFactory<CComponent, CBuilder<CComponent>, ComponentType>;
	friend CSingleton<CFactoryMgr>;
private:
	CFactoryMgr();
	virtual ~CFactoryMgr() override;

public:
	void Initialize();
	void Release();

public:
	CObject*	Build_Object(ObjectType _eObjectType);
	CComponent* Build_Component(ComponentType _eComponentType, CObject* _pOwner);

private:
	void		Init_Object_Factory();
	void		Init_Component_Factory();

public:
	ObjectFactory		m_tObjectFactory{};
	ComponentFactory	m_tComponentFactory{};
};
#define FACTORY										CFactoryMgr::Get_Instance()
#define BUILD_OBJECT(_eObjectType)					FACTORY.Build_Object(_eObjectType)
#define BUILD_COMPONENT(_eComponentType, _pOwner)	FACTORY.Build_Component(_eComponentType, _pOwner)