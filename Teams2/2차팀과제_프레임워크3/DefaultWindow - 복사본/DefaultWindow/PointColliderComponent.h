#pragma once
#include "Define.h"
#include "ColliderComponent.h"
class CPointColliderComponent :public CColliderComponent
{

public:
	CPointColliderComponent(ComponentType _eComponentType);
	virtual void Render() override;
	virtual ~CPointColliderComponent();

public:
	Point2F Get_Prev_Point_Pos()							{ return m_tPrevPointPos; }
	Point2F Get_Cur_Point_Pos()								{ return m_tCurPointPos; }

	void	Set_Projection_Pos(Point2F _tProjectionPos)		{ m_tProjectionPos = _tProjectionPos; }
	Point2F Get_Projection_Pos()							{ return m_tProjectionPos; }

	void	Set_Activated(bool _bActivated)					{ m_bActivated = _bActivated; }
	bool	Get_Activated()									{ return m_bActivated; }

protected:
	Point2F m_tPrevPointPos{};
	Point2F m_tCurPointPos{};
	Point2F m_tProjectionPos{};
	bool	m_bActivated{ true };
};

