#pragma once
#include "Define.h"
#include "State.h"
#include "PlayerFSMComponent.h"
#include "LineColliderComponent.h"
class CPlayerOnLineState :public CState<PlayerState>
{
public:
	CPlayerOnLineState(CObject* _pOwner, CFSMComponent<PlayerState>* _pFSMComponent);

public:
	virtual void Init()		override;
	virtual void On_Enter()	override;
	virtual void On_Stay()	override;
	virtual void On_Exit()	override;

public:
	void Set_Connected_Line(Line2F _tLine) { m_tLine = _tLine; }
	bool On_Line();

private:
	Line2F m_tLine{};

};

