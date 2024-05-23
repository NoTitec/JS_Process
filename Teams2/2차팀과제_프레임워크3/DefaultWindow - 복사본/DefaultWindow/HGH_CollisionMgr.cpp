#include "stdafx.h"
#include "HGH_CollisionMgr.h"
#include "Object.h"
#include "ObjMgr.h"
HGH_CollisionMgr::HGH_CollisionMgr()
{
}

HGH_CollisionMgr::~HGH_CollisionMgr()
{
}

void HGH_CollisionMgr::Late_Update()
{
	for (int layer1{}; layer1 < E2I(ObjectType::End)-1; ++layer1)
	{
		for (int layer2{ layer1 + 1 }; layer2 < E2I(ObjectType::End); ++layer2)
		{
			for (auto pCollider1 : m_pColliderList[layer1])
			{
				for (auto pCollider2 : m_pColliderList[layer2])
				{
					if (Check_Collision(pCollider1, pCollider2))
					{
						pCollider1->On_Collision(pCollider2);
						pCollider2->On_Collision(pCollider1);			
					}
				}
			}
		}
	}
}

void HGH_CollisionMgr::Push_Back_Collider(CColliderComponent* _pCollider)
{
	m_pColliderList[E2I(_pCollider->Get_Owner_Type())].push_back(_pCollider);
}

void HGH_CollisionMgr::Pop_Back_Collider(CColliderComponent* _pCollider)
{
	m_pColliderList[E2I(_pCollider->Get_Owner_Type())].remove(_pCollider);
}

list<CLineColliderComponent*> HGH_CollisionMgr::Get_Line_Collider_List()
{
	list<CLineColliderComponent*> pLineColliderList{};
	for (auto pCollider : m_pColliderList[E2I(ObjectType::Line)])
	{
		if (pCollider->Get_Collider_Type() == ColliderType::Line)
		{
			pLineColliderList.push_back(static_cast<CLineColliderComponent*>(pCollider));
		}
	}
	return pLineColliderList;
}

bool HGH_CollisionMgr::Check_Collision(CColliderComponent* _pCollider1, CColliderComponent* _pCollider2)
{
	ColliderType eColliderType1{ _pCollider1->Get_Collider_Type() };
	ColliderType eColliderType2{ _pCollider2->Get_Collider_Type() };

	if ( (eColliderType1 == ColliderType::Point && eColliderType2 == ColliderType::Line ) ||
		 (eColliderType1 == ColliderType::Line  && eColliderType2 == ColliderType::Point) )
	{
		CPointColliderComponent* pPointCollider{ eColliderType1 == ColliderType::Point ? static_cast<CPointColliderComponent*>(_pCollider1) : static_cast<CPointColliderComponent*>(_pCollider2) };
		CLineColliderComponent* pLineCollider{ eColliderType1 == ColliderType::Line ? static_cast<CLineColliderComponent*>(_pCollider1) : static_cast<CLineColliderComponent*>(_pCollider2) };
		return Check_Point_To_Line_Collision(pPointCollider, pLineCollider);
	}

	return true;
}

bool HGH_CollisionMgr::Check_Point_To_Line_Collision(CPointColliderComponent* _pPointCollider, CLineColliderComponent* _pLineCollider)
{
	if (!_pPointCollider->Get_Activated()) return false;

	LineType eLineType{ _pLineCollider->Get_Line_Type() };
	switch (eLineType)
	{
	case LineType::Push_Up_Line:
		return Check_Point_To_Push_Up_Line_Collision(_pPointCollider, static_cast<CPushUpLineColliderComponent*>(_pLineCollider));
	case LineType::Push_Left_Line:

		break;

	case LineType::Push_Right_Line:
		
		break;

	case LineType::Ladder_Line:

		break;
	}
	return false;
}

bool HGH_CollisionMgr::Check_Point_To_Push_Up_Line_Collision(CPointColliderComponent* _pPointCollider, CPushUpLineColliderComponent* _pPushUpLineCollider)
{
	if (_pPointCollider->Get_Owner()->m_tPos.y >= 502)
	{
		bool res{ false };
	}
	Line2F line{ _pPushUpLineCollider->Get_Line() };
	Point2F p1{ line.p1 };
	Point2F p2{ line.p2 };
	Point2F prev{ _pPointCollider->Get_Prev_Point_Pos() };
	Point2F cur{ _pPointCollider->Get_Cur_Point_Pos() };

	Vec2F unitX{ 1.f,0.f };
	Vec2F prevcur{ cur.x - prev.x, cur.y - prev.y };
	//if (prevcur.y < 0) return false;
	Vec2F prevp1{ p1.x - prev.x,p1.y - prev.y };
	Vec2F prevp2{ p2.x - prev.x, p2.y - prev.y };
	float unitX_dot_prevcur{ unitX.x * prevcur.x + unitX.y * prevcur.y };
	float cos_from_unitX_to_prevcur{ unitX_dot_prevcur / (unitX.Get_Length() * prevcur.Get_Length()) };
	float theta_from_unitX_to_prevcur{ acosf(cos_from_unitX_to_prevcur) };

	if (prevcur.y > 0)
	{
		theta_from_unitX_to_prevcur = -theta_from_unitX_to_prevcur;
	}

	Vec2F prevp1_rotated{ prevp1.Rotate(theta_from_unitX_to_prevcur) };
	Vec2F prevp2_rotated{ prevp2.Rotate(theta_from_unitX_to_prevcur) };
	if (prevp1_rotated.y * prevp2_rotated.y > 0)
	{
		return false;
	}

	Vec2F p1p2{ p2.x - p1.x, p2.y - p1.y };
	Vec2F p1cur{ cur.x - p1.x, cur.y - p1.y };
	Vec2F p1prev{ prev.x - p1.x,prev.y - p1.y };
	float unitX_dot_p1p2{ unitX.x * p1p2.x + unitX.y * p1p2.y };
	float cos_from_unitX_to_p1p2{ unitX_dot_p1p2 / (unitX.Get_Length() * p1p2.Get_Length()) };
	float theta_from_unitX_to_p1p2{ acosf(cos_from_unitX_to_p1p2) };
	if (p1p2.y > 0)
	{
		theta_from_unitX_to_p1p2 = -theta_from_unitX_to_p1p2;
	}

	Vec2F p1cur_rotated{ p1cur.Rotate(theta_from_unitX_to_p1p2) };
	Vec2F p1prev_rotated{ p1prev.Rotate(theta_from_unitX_to_p1p2) };
	if (p1cur_rotated.y * p1prev_rotated.y > 0)
	{
		return false;
	}
	if (p1cur_rotated.y <= 0) return false;
	//if (p1cur_rotated.y < 0) return false;  // 이렇게 했을 때 왜 Jumping Enter가 안불릴까?

	

	float slope{ (p2.y - p1.y) / (p2.x - p1.x) };
	float curProjectionY{ p1.y + slope * (cur.x - p1.x) };
	/*
	float prevProjectionY{ line.p1.y + slope * (prev.x - line.p1.x) };
	if (prev.y == prevProjectionY)
	{
		_pPointCollider->Set_Cross_Point_Pos(Point2F{ cur.x,curProjectionY });
		return true;
	}
	*/
	_pPointCollider->Set_Projection_Pos(Point2F{ cur.x,curProjectionY } - Point2F{ 0.f, _pPointCollider->Get_Owner()->m_tScale.y });
	return true;
}


