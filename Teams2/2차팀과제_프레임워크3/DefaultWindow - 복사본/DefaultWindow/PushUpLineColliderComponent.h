#pragma once
#include "LineColliderComponent.h"
class CPushUpLineColliderComponent :public CLineColliderComponent
{
public:
	CPushUpLineColliderComponent(ComponentType _eComponentType);
	virtual ~CPushUpLineColliderComponent() override;

public:
	void On_Collision(CColliderComponent* _pOtherCollider) override;


};

