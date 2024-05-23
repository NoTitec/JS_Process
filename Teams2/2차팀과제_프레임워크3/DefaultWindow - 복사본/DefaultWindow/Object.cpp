#include "stdafx.h"
#include "Object.h"
#include "KeyMgr.h"
int CObject::s_iObjectID{};

CObject::CObject(ObjectType _eObjectType) :
	m_eObjectType(_eObjectType)
{
}

CObject::~CObject()
{
	Release();
}

void CObject::Initialize()
{
}

int CObject::Update()
{
	for (int endIndex{ (int)m_pComponentVec.size() - 1 }; endIndex >= 0; --endIndex)
	{
		if (m_pComponentVec[endIndex]->m_bDead)
		{
			Safe_Delete(m_pComponentVec[endIndex]);
			m_pComponentVec[endIndex] = m_pComponentVec.back();
			m_pComponentVec.pop_back();
		}
		else
		{
			m_pComponentVec[endIndex]->Update();
		}
	}
	return m_bDead;
}

void CObject::Late_Update()
{
	for (auto pComponent : m_pComponentVec)
	{
		pComponent->Late_Update();
	}
}

void CObject::Render(HDC _hDC)
{
	for (auto pComponent : m_pComponentVec)
	{
		pComponent->Render();
	}
}

void CObject::Release()
{
	Clear_All_Components();
}

CComponent* CObject::Get_Component(ComponentType _eComponentType)
{
	for (auto pComponent : m_pComponentVec)
	{
		if (pComponent->Get_Type() == _eComponentType)
		{
			return pComponent;
		}
	}
	return nullptr;
}

void CObject::Push_Back_Component(CComponent* _pComponent)
{
	if (_pComponent == nullptr) return;

	for (auto pComponent : m_pComponentVec)
	{
		if (pComponent->Get_Type() == _pComponent->Get_Type())
		{
			return;
		}
	}
	m_pComponentVec.push_back(_pComponent);
}

void CObject::Pop_Back_Component(ComponentType _type)
{
	for (auto pComponent : m_pComponentVec)
	{
		if (pComponent->Get_Type() == _type)
		{
			pComponent->m_bDead = true;
			return;
		}
	}
}

void CObject::Clear_All_Components()
{
	for (auto& pComponent : m_pComponentVec)
	{
		Safe_Delete(pComponent);
	}
	m_pComponentVec.clear();
}

void CObject::OnHit(CObj* _pObj)
{
}

