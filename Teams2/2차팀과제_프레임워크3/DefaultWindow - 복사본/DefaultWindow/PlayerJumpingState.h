#pragma once
#include "State.h"
#include "FSMComponent.h"
#include "PlayerFSMComponent.h"
class CPlayerJumpingState :public CState<PlayerState>
{
public:
	CPlayerJumpingState(CObject* _pObject, CFSMComponent<PlayerState>* _pFSMComponent);
	virtual ~CPlayerJumpingState() override;

public:
	void Init()		override;
	void On_Enter()	override;
	void On_Stay()	override;
	void On_Exit()	override;

};

