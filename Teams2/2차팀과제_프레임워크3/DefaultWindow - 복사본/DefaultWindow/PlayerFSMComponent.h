#pragma once
#include "Define.h"
#include "FSMComponent.h"
#include "State.h"

enum class PlayerState
{
	OnLine,
	Jumping,
	DownJumping,
	End
};

class CPlayerFSMComponent :public  CFSMComponent<PlayerState>
{
public:
	CPlayerFSMComponent(ComponentType _eComponentType);
	virtual ~CPlayerFSMComponent() override;
public:
	virtual void Init()			override;
	virtual void Render()		override;
};

