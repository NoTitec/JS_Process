#pragma once
#include "State.h"
#include "PlayerFSMComponent.h"
#include "Object.h"
class CPlayerDownJumpingState :public CState<PlayerState>
{
public:
	CPlayerDownJumpingState(CObject* _pObject, CFSMComponent<PlayerState>* _pFSMComponent);
	virtual ~CPlayerDownJumpingState() override;

public:
	void Init() override;
	void On_Enter() override;
	void On_Stay() override;
	void On_Exit() override;

};

