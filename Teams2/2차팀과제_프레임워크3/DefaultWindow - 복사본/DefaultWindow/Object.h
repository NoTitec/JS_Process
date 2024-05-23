#pragma once

#include "Define.h"
#include "Obj.h"
#include "Component.h"

enum class ObjectType
{
	Line,
	Monster,
	Player,
	End
};

class CObject :public CObj
{
public:
	CObject(ObjectType _eObjectType);
	virtual ~CObject();

public:
//	virtual void	Init()					override;
	virtual void	Initialize()			override;
	virtual int		Update()				override;
	virtual void	Late_Update()			override;
	virtual void	Render(HDC _hDC)		override;
	virtual void	Release()				override;

public:
	// TODO: 동일한 타입의 컴포넌트를 중복해서 집어넣을 수 있게 <- CColliderComponent
	CComponent* Get_Component(ComponentType _eComponentType);
	void		Push_Back_Component(CComponent* _pComponent);	// CREATE_COMPONENT(_eComponentType)으로 생성된 객체를 인자로 받는다
	void		Pop_Back_Component(ComponentType _type);
	void		Clear_All_Components();

public:
	ObjectType	Get_Type() { return m_eObjectType; }

public:
	//bool				m_bDead{};
	Point2F				m_tPos{};
	Vec2F				m_tScale{};
	Vec2F				m_tUnitDirection{};
	Vec2F				m_tSpeed{};
	//RECT				m_tRect{};

private:
	ObjectType			m_eObjectType;
	vector<CComponent*> m_pComponentVec{};

	int					m_iObjectID{ s_iObjectID++ };
	static int			s_iObjectID;

	// CObj을(를) 통해 상속됨
	void OnHit(CObj* _pObj) override;
};

