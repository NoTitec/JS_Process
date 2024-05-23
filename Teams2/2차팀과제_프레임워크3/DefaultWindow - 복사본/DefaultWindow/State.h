#pragma once
#include "Define.h"
#include "Object.h"
#include "FSMComponent.h"

template<typename StateType>
class CState
{
public:
	CState(CObject* _pOwner, CFSMComponent<StateType>* _pFSMComponent);
	virtual ~CState() {};

public:
	virtual void		Init()			PURE;
	virtual void		Update();

public:
	virtual void		On_Enter()		PURE;
	virtual void		On_Stay()		PURE;
	virtual void		On_Exit()		PURE;

	void				Enter_State_To(StateType _eStateType);
	void				Change_State_To(StateType _eStateType);

protected:
	CObject*							m_pObject;
	CFSMComponent<StateType>*			m_pFSMComponent;
};

template<typename StateType>
inline CState<StateType>::CState(CObject* _pOwner, CFSMComponent<StateType>* _pFSMComponent):
	m_pObject{_pOwner},
	m_pFSMComponent{ _pFSMComponent }
{
}

template<typename StateType>
inline void CState<StateType>::Update()
{
	if (m_pFSMComponent->m_uPhase == ENTER)
	{
		On_Enter();

		m_pFSMComponent->m_uPhase = STAY;
	}
	if (m_pFSMComponent->m_uPhase == STAY)
	{
		On_Stay();
	}
}

template<typename StateType>
inline void CState<StateType>::Enter_State_To(StateType _eStateType)
{
	m_pFSMComponent->m_uPhase = ENTER;
	m_pFSMComponent->m_eStateType = _eStateType;
}

template<typename StateType>
inline void CState<StateType>::Change_State_To(StateType _eStateType)
{
	On_Exit();
	m_pFSMComponent->m_uPhase = ENTER;
	m_pFSMComponent->m_eStateType = _eStateType;
	m_pFSMComponent->m_pState = m_pFSMComponent->m_pStateArray[E2I(m_pFSMComponent->m_eStateType)];
}


