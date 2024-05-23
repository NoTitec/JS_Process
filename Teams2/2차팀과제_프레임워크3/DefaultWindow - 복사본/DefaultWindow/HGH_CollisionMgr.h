#pragma once
#include "Define.h"
#include "Singleton.h"
#include "Object.h"
#include "ColliderComponent.h"
#include "PointColliderComponent.h"
#include "LineColliderComponent.h"
#include "PushUpLineColliderComponent.h"
class HGH_CollisionMgr :public CSingleton<HGH_CollisionMgr>
{
	friend CSingleton<HGH_CollisionMgr>;
private:
	HGH_CollisionMgr();
	virtual ~HGH_CollisionMgr() override;

public:
	void Late_Update();
	void Push_Back_Collider(CColliderComponent* _pCollider);
	void Pop_Back_Collider(CColliderComponent* _pCollider);

public:
	list<CLineColliderComponent*> Get_Line_Collider_List();

private:
	bool Check_Collision(CColliderComponent* _pCollider1, CColliderComponent* _pCollider2);

#pragma region Point_To_Line
	bool Check_Point_To_Line_Collision(CPointColliderComponent* _pPointCollider, CLineColliderComponent* _pLineCollider);
	bool Check_Point_To_Push_Up_Line_Collision(CPointColliderComponent* _pPointCollider, CPushUpLineColliderComponent* _pPushUpLineCollider);
#pragma endregion
private:
	array<list<CColliderComponent*>, E2I(ObjectType::End)> m_pColliderList{};

};
#define HGH_COLLISION HGH_CollisionMgr::Get_Instance()

