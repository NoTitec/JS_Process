#pragma once
#include "Define.h"
#include "Component.h"

class CRectangleRendererComponent :public CComponent
{
public:
	CRectangleRendererComponent(ComponentType _eComponentType);
	virtual ~CRectangleRendererComponent();

public:
	virtual void Init()				override;
	virtual void Update()			override;
	virtual void Late_Update()		override;
	virtual void Render()			override;
	virtual void Release()			override;
};

