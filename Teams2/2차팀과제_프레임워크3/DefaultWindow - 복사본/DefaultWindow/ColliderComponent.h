#pragma once
#include "Component.h"
#include "Object.h"

enum class ColliderType
{
	Point,
	Line,
	End
};

class CColliderComponent :public CComponent
{
public:
	CColliderComponent(ComponentType _eComponentType);
	virtual ~CColliderComponent();
public:
	void Init()				override;
	void Update()			override;
	void Late_Update()		override;
	void Render()			override;
	void Release()			override;

public:
	virtual void	On_Collision(CColliderComponent* _pOtherCollider) PURE;
	ColliderType	Get_Collider_Type()	{ return m_eColliderType; };

protected:
	ColliderType	m_eColliderType{};
};

