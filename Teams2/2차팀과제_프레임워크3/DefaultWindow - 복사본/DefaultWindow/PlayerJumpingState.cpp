#include "stdafx.h"
#include "PlayerJumpingState.h"
#include "KeyMgr.h"

CPlayerJumpingState::CPlayerJumpingState(CObject* _pObject, CFSMComponent<PlayerState>* _pFSMComponent):
	CState<PlayerState>::CState(_pObject,_pFSMComponent)
{
}

CPlayerJumpingState::~CPlayerJumpingState()
{
}

void CPlayerJumpingState::Init()
{
}

void CPlayerJumpingState::On_Enter()
{
	cout << "PlayerState : Jumping::ENTER" << endl;
	m_pObject->m_tSpeed.y = -15.f;
}

void CPlayerJumpingState::On_Stay()
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
	if (KEY.Key_Down(VK_SPACE))
	{
		cout << "Jumping 상태 중 점프 불가능" << endl;
	}
}

void CPlayerJumpingState::On_Exit()
{
	cout << "PlayerState : Jumping::EXIT" << endl;
}
