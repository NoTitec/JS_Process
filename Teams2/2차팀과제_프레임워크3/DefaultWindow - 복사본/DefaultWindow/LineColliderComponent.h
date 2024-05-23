#pragma once
#include "ColliderComponent.h"

enum class LineType
{
	Push_Up_Line,
	Push_Left_Line,
	Push_Right_Line,
	Ladder_Line,
	End
};
class CLineColliderComponent :public CColliderComponent
{
public:
	CLineColliderComponent(ComponentType _eComponentType);
	virtual ~CLineColliderComponent() override;

public:
	void Render() override;
	

public:
	LineType	Get_Line_Type()				{ return m_eLineType; }

	void		Set_Line(Line2F _tLine)		{ m_tLine = _tLine.p1.x < _tLine.p2.x ? Line2F{ _tLine.p1,_tLine.p2 } : Line2F{ _tLine.p2,_tLine.p1 }; }
	Line2F		Get_Line()					{ return m_tLine; };



protected:
	LineType	m_eLineType{};
	Line2F		m_tLine{};

};

