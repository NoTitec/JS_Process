#pragma once
#include "Define.h"
#include "Singleton.h"

template<typename ReturnType, typename BuilderType, typename EnumType>
class CFactory
{

public:
	virtual ~CFactory();

public:
	ReturnType* Build(EnumType _eType);
	void Insert_Builder(EnumType _eType, BuilderType* _pBuilder);
	void Erase_Builder(EnumType _eType);
	void Clear_All_Builders();

private:
	unordered_map<EnumType, BuilderType*> m_pBuilderMap{};
};

template<typename ReturnType, typename BuilderType, typename EnumType>
inline CFactory<ReturnType, BuilderType, EnumType>::~CFactory()
{
	Clear_All_Builders();
}

template<typename ReturnType, typename BuilderType, typename EnumType>
inline ReturnType* CFactory<ReturnType, BuilderType, EnumType>::Build(EnumType _eType)
{
	auto iter = m_pBuilderMap.find(_eType);
	if (iter == m_pBuilderMap.end())
		return nullptr;
	return iter->second->Build();
}

template<typename ReturnType, typename BuilderType, typename EnumType>
inline void CFactory<ReturnType, BuilderType, EnumType>::Insert_Builder(EnumType _eType, BuilderType* _pBuilder)
{
	m_pBuilderMap.insert({ _eType, _pBuilder });
}

template<typename ReturnType, typename BuilderType, typename EnumType>
inline void CFactory<ReturnType, BuilderType, EnumType>::Erase_Builder(EnumType _eType)
{
	m_pBuilderMap.erase(_eType);
}

template<typename ReturnType, typename BuilderType, typename EnumType>
inline void CFactory<ReturnType, BuilderType, EnumType>::Clear_All_Builders()
{
	for (auto pBuilder : m_pBuilderMap)
	{
		Safe_Delete(pBuilder.second);
	}
	m_pBuilderMap.clear();
}
