#pragma once
#include "Define.h"
#include "Component.h"
template<typename StateType>
class CState;

#define ENTER	0
#define STAY	1
#define EXIT	2

template<typename StateType>
class CFSMComponent :public CComponent
{
	using StatePhase = int;
		
public:
	CFSMComponent(ComponentType _eComponentType);
	virtual ~CFSMComponent() override;

public:
	virtual void Init()			PURE;
	virtual void Update()		override;
	virtual void Late_Update()	{}
	virtual void Render()		{}
	virtual void Release()		override;

public:
	void Set_Phase(StatePhase _uPhase);
	void Set_State_Type(StateType _eStateType);
	void Set_State();

public:
	StatePhase															m_uPhase{ ENTER };
	StateType															m_eStateType{};
	CState<StateType>*													m_pState{};
	std::array<CState<StateType>*, E2I(StateType::End)>					m_pStateArray{};
};

template<typename StateType>
inline CFSMComponent<StateType>::CFSMComponent(ComponentType _eComponentType):
	CComponent::CComponent{_eComponentType}
{
}

template<typename StateType>
inline CFSMComponent<StateType>::~CFSMComponent()
{
	Release();
}

template<typename StateType>
inline void CFSMComponent<StateType>::Update()
{
	m_pState->Update();
}

template<typename StateType>
inline void CFSMComponent<StateType>::Release()
{
	for (auto pState : m_pStateArray)
	{
		Safe_Delete(pState);
	}
	m_pState = nullptr;
}

template<typename StateType>
inline void CFSMComponent<StateType>::Set_Phase(StatePhase _uPhase)
{
	m_uPhase = _uPhase;
}

template<typename StateType>
inline void CFSMComponent<StateType>::Set_State_Type(StateType _eNextStateType)
{
	m_eStateType = _eNextStateType;
	m_pState = m_pStateArray[E2I(m_eStateType)];
}

template<typename StateType>
inline void CFSMComponent<StateType>::Set_State()
{
	m_pState = m_pStateArray[E2I(m_eStateType)];
}
