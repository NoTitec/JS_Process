#include "stdafx.h"
#include "PlayerDownJumpingState.h"
#include "KeyMgr.h"
#include "PointColliderComponent.h"
CPlayerDownJumpingState::CPlayerDownJumpingState(CObject* _pObject, CFSMComponent<PlayerState>* _pFSMComponent):
	CState<PlayerState>::CState(_pObject,_pFSMComponent)
{
}

CPlayerDownJumpingState::~CPlayerDownJumpingState()
{
}

void CPlayerDownJumpingState::Init()
{
}

void CPlayerDownJumpingState::On_Enter()
{
	cout << "PlayerState : DownJumping::ENTER" << endl;
	m_pObject->m_tSpeed.y = 0;
}

void CPlayerDownJumpingState::On_Stay()
{
	m_pObject->m_tSpeed.y += 1.f;
	m_pObject->m_tPos.y += m_pObject->m_tSpeed.y;
	if (KEY.Key_Pressing(VK_RIGHT))
	{
		m_pObject->m_tPos.x += m_pObject->m_tSpeed.x;
	}
	if (KEY.Key_Pressing(VK_LEFT))
	{
		m_pObject->m_tPos.x -= m_pObject->m_tSpeed.x;
	}
	if (KEY.Key_Down('R'))
	{
		m_pObject->m_tPos = { 200,400 };
		Change_State_To(PlayerState::DownJumping);
	}
}

void CPlayerDownJumpingState::On_Exit()
{
	cout << "PlayerState : DownJumping::EXIT" << endl;
}
