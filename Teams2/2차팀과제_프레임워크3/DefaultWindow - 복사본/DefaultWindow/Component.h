#pragma once
#include "Define.h"

class CObject;
enum class ObjectType;

enum class ComponentType
{
	PlayerFSM,
	RectangleRenderer,
	PlayerRenderer,
	PushUpLineCollider,
	PlayerPointCollider,
	End
};

class CComponent
{

public:
	CComponent(ComponentType _eComponentType);
	virtual ~CComponent();

public:
	virtual void Init()				PURE;
	virtual void Update()			PURE;
	virtual void Late_Update()		PURE;
	virtual void Render()			PURE;
	virtual void Release()			PURE;

public:
	ComponentType	Get_Type()					{ return m_eComponentType; }

	void			Set_Owner(CObject* _pOwner) { m_pOwner = _pOwner; }
	CObject*		Get_Owner()					{ return m_pOwner; }
	ObjectType		Get_Owner_Type();

public:
	bool				m_bDead{};

protected:
	ComponentType		m_eComponentType;
	CObject*			m_pOwner{};

	int					m_iComponentID{s_iComponentID++};
	static int			s_iComponentID;
};

