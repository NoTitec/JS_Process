#pragma once
#include "PointColliderComponent.h"
#include "LineColliderComponent.h"
class CPlayerPointColliderComponent :public CPointColliderComponent
{
public:
	CPlayerPointColliderComponent(ComponentType _eComponentType);
	virtual ~CPlayerPointColliderComponent();
	virtual void Init()			override;
	virtual void Update()		override;
	virtual void Late_Update()	override;

public:
	void On_Collision(CColliderComponent* _pOtherCollider) override;

private:
	void On_Push_Up_Line(CLineColliderComponent* _pLineCollider);
};

