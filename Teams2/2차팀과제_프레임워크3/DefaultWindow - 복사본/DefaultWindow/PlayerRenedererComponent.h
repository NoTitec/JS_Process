#pragma once
#include "Component.h"
class CPlayerRenedererComponent :public CComponent
{
public:
	CPlayerRenedererComponent(ComponentType _eCompoonentType);
	virtual ~CPlayerRenedererComponent();

public:
	void Init()				override;
	void Update()			override;
	void Late_Update()		override;
	void Render()			override;
	void Release()			override;

};

