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
	// TODO: ������ Ÿ���� ������Ʈ�� �ߺ��ؼ� ������� �� �ְ� <- CColliderComponent
	CComponent* Get_Component(ComponentType _eComponentType);
	void		Push_Back_Component(CComponent* _pComponent);	// CREATE_COMPONENT(_eComponentType)���� ������ ��ü�� ���ڷ� �޴´�
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

	// CObj��(��) ���� ��ӵ�
	void OnHit(CObj* _pObj) override;
};

