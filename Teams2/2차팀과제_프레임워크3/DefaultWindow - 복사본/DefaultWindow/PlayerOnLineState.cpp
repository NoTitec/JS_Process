#include "stdafx.h"
#include "PlayerOnLineState.h"
#include "KeyMgr.h"
#include "HGH_CollisionMgr.h"
#include "PointColliderComponent.h"
CPlayerOnLineState::CPlayerOnLineState(CObject* _pOwner, CFSMComponent<PlayerState>* _pFSMComponent):
	CState<PlayerState>::CState(_pOwner, _pFSMComponent)
{
}

void CPlayerOnLineState::Init()
{
}

bool CPlayerOnLineState::On_Line()
{
	bool isLineChanged{true};
	if (m_pObject->m_tPos.x < m_tLine.p1.x)
	{
		list<CLineColliderComponent*> pLineColliderList{ HGH_COLLISION.Get_Line_Collider_List() };
		for (auto pLineCollider : pLineColliderList)
		{
			Line2F otherLine{ pLineCollider->Get_Line() };
			if (otherLine.p2.x == m_tLine.p1.x &&
				otherLine.p2.y == m_tLine.p1.y &&
				pLineCollider->Get_Line_Type() == LineType::Push_Up_Line)
			{
				m_tLine = otherLine;
				Change_State_To(PlayerState::OnLine);
				return true;
			}
		}
		isLineChanged = false;
	}
	if (m_tLine.p2.x < m_pObject->m_tPos.x)
	{
		list<CLineColliderComponent*> pLineColliderList{ HGH_COLLISION.Get_Line_Collider_List() };
		for (auto pLineCollider : pLineColliderList)
		{
			Line2F otherLine{ pLineCollider->Get_Line() };
			if (otherLine.p1.x == m_tLine.p2.x &&
				otherLine.p1.y == m_tLine.p2.y &&
				pLineCollider->Get_Line_Type() == LineType::Push_Up_Line)
			{
				m_tLine = otherLine;
				Change_State_To(PlayerState::OnLine);
				return true;

			}
		}
		isLineChanged = false;
	}
	return isLineChanged;
}

void CPlayerOnLineState::On_Enter()
{
	cout << "PlayerState : OnLine::ENTER" << endl;
	static_cast<CPointColliderComponent*>(m_pObject->Get_Component(ComponentType::PlayerPointCollider))->Set_Activated(false);
	m_pObject->m_tSpeed.y = 0;
}

void CPlayerOnLineState::On_Stay()
{

	float slope{ (m_tLine.p2.y - m_tLine.p1.y) / (m_tLine.p2.x - m_tLine.p1.x) };
	float theta{ atanf(slope) };
	if (KEY.Key_Pressing(VK_RIGHT))
	{
		m_pObject->m_tPos.x += cosf(theta) * m_pObject->m_tSpeed.x;
	}
	else if (KEY.Key_Pressing(VK_LEFT))
	{
		m_pObject->m_tPos.x -= cosf(theta) * m_pObject->m_tSpeed.x;
	}

	if (!On_Line()) Change_State_To(PlayerState::DownJumping);
	else
	{
		slope = (m_tLine.p2.y - m_tLine.p1.y) / (m_tLine.p2.x - m_tLine.p1.x);
	}
	m_pObject->m_tPos.y = m_tLine.p1.y + slope * (m_pObject->m_tPos.x - m_tLine.p1.x) - m_pObject->m_tScale.y;

	if (KEY.Key_Down(VK_SPACE))
	{
		Change_State_To(PlayerState::Jumping);
	}
}

void CPlayerOnLineState::On_Exit()
{
	static_cast<CPointColliderComponent*>(m_pObject->Get_Component(ComponentType::PlayerPointCollider))->Set_Activated(true);
	cout << "PlayerState : OnLine::EXIT" << endl;
}
